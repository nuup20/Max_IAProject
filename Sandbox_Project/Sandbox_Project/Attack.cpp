#include "stdafx.h"
#include "Attack.h"
#include "Soldier.h"
#include "GameScene.h"
#include "Flag.h"
#include "Base.h"

void CAttack::onEnter()
{
	if (m_Soldier->enemyBase() != nullptr)
	{
		m_Soldier->addNewTarget(m_Soldier->enemyBase(), BOIDTARGET::kSeek);		
	}
	else
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
	}
	m_Soldier->m_stateDebug = "Attack";
}
	

unsigned int CAttack::update(void * pObject)
{
	CVector3 vec_ToEnemyBase =  m_Soldier->enemyBase()->m_position - m_Soldier->m_position;

	if (m_Soldier->enemyInSight() != nullptr)
	{
		//OH SHIT, UN ENEMIGO TENGO QUE REVENTARLO
		m_Soldier->m_fsm.SetState(BOIDSTATE::kAttackEnemy);
		return 0;
	}

	//¿BASE ENEMIGA A LA VISTA?
	if (vec_ToEnemyBase.magnitud() <= (m_Soldier->BOID_VISION - 10))
	{		
		//¿HAY BANDERA ENEMIGA EN LA BASE?
		CFlag* enemyFlag = m_Soldier->enemyFlagInSight();		
		if (enemyFlag != nullptr)
		{		
			if (!enemyFlag->isEnable())
			{
				m_Soldier->m_fsm.SetState(BOIDSTATE::kToBase);
				return 0;
			}			
		}
		else {
			m_Soldier->m_fsm.SetState(BOIDSTATE::kToBase);
			return 0;
		}		
		
		//SI HAY BANDERA, REVISA SI PUEDE TOMARLA
		if ((enemyFlag->m_position - m_Soldier->m_position).magnitud() <= m_Soldier->BOID_RADIUS)
		{
			// TOMA LA BANDERA ENEMIGA, REGRESA A LA BASE AMIGA
			m_Soldier->setFlagPower(true);
			enemyFlag->setEnable(false);
			m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
			return 0;
		}
	}

	// LÍDER A LA VISTA	
	CSoldier* leader = m_Soldier->leaderInSight();
	if (leader != nullptr)
	{
		//SEGUIR AL LIDER
		m_Soldier->m_fsm.SetState(BOIDSTATE::kDefendLeader);
	}

	return 0;	
}

void CAttack::onExit()
{
	m_Soldier->removeTarget(BOIDTARGET::kSeek);	
}

CAttack::CAttack(CSoldier * mySoldier) : CBoidState(BOIDSTATE::kAttack, mySoldier)
{

}

CAttack::~CAttack()
{
}
