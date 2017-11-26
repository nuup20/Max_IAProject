#include "stdafx.h"
#include "ToBase.h"
#include "Soldier.h"
#include "Fsm.h"
#include "Base.h"
#include "GameScene.h"
#include "Flag.h"

void CToBase::onEnter()
{
	if (m_Soldier->enemyBase() != nullptr)
	{
		m_Soldier->addNewTarget(m_Soldier->friendlyBase(), BOIDTARGET::kSeek);
	}
	else
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
	}
	m_Soldier->m_stateDebug = "To Base";
}

unsigned int CToBase::update(void * pObject)
{
	CVector3 vec_ToFriendlyBase = m_Soldier->friendlyBase()->m_position - m_Soldier->m_position;
	CGameScene* gmscn = reinterpret_cast<CGameScene*>(pObject);

	//¿BASE AMIGA A LA VISTA?
	if (vec_ToFriendlyBase.magnitud() <= m_Soldier->BOID_VISION)
	{		
		//¿HE LLEGADO A LA BASE?
		if (vec_ToFriendlyBase.magnitud() <= m_Soldier->BOID_RADIUS)
		{
			// ¿POSEO LA BANDERA ENEMIGA?
			if (m_Soldier->flagPower())
			{
				//ANOTO UN PUNTO
				m_Soldier->setFlagPower(false);

				//LA BANDERA ENEMIGA REGRESA A SU POSICIÓN				
				vector<CFlag*> flags = gmscn->getObjs<CFlag>();

				for (int i = 0; i < flags.size(); ++i)
				{
					if (flags[i]->flagTeam() != m_Soldier->soldierTeam())
					{
						if (!flags[i]->isEnable())
						{
							flags[i]->setEnable(true);
							break;
						}
					}
				}
			}
			// REGRESO A IDLE
			m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
			return 0;
		}
	}

	//¿LIDER A LA VISTA?
	CSoldier* leader = m_Soldier->leaderInSight();
	if (leader != nullptr)
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kDefendLeader);
	}

	//¿HAY BANDERA ENEMIGA EN LA BASE?
	CFlag* enemyFlag = m_Soldier->enemyFlagInSight();
	if (enemyFlag != nullptr)
	{
		if (enemyFlag->isEnable())
		{
			// VAMOS POR LA BANDERA CARAJO!
			m_Soldier->m_fsm.SetState(BOIDSTATE::kAttack);
			return 0;
		}
	}

	return 0;
}

void CToBase::onExit()
{
	m_Soldier->removeTarget(BOIDTARGET::kSeek);
}

CToBase::CToBase(CSoldier * mySoldier) : CBoidState(BOIDSTATE::kToBase, mySoldier)
{

}

CToBase::~CToBase()
{
}
