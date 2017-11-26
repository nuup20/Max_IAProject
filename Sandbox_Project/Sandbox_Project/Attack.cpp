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
}
	

unsigned int CAttack::update(void * pObject)
{
	CVector3 vec_ToEnemyBase =  m_Soldier->enemyBase()->m_position - m_Soldier->m_position;

	//¿BASE ENEMIGA A LA VISTA?
	if (vec_ToEnemyBase.magnitud() <= (m_Soldier->BOID_VISION - 10))
	{
		vector<CFlag*> flag_list = m_Soldier->objectsAtVisionRange<CFlag>();
		CFlag* enemyFlag = nullptr;
		
		//SI NO HAY BANDERA ENEMIGA EN LA POSICIÓN, REGRESA A LA BASE
		for (unsigned int i = 0; i < flag_list.size(); ++i)
		{
			if (flag_list[i]->flagTeam() != m_Soldier->soldierTeam() 
				&& flag_list[i]->flagTeam() != TEAM::kUndefined)
			{
				enemyFlag = flag_list[i];
				break;
			}
		}

		if (enemyFlag == nullptr)
		{			
			m_Soldier->m_fsm.SetState(BOIDSTATE::kToBase);
			return 0;
		}
		if (!enemyFlag->isEnable())
		{
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
