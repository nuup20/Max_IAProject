#include "stdafx.h"
#include "Idle.h"
#include "Soldier.h"
#include "Fsm.h"

void CIdle::onEnter()
{
	m_Soldier->m_stateDebug = "Idle";
}

unsigned int CIdle::update(void * pObject)
{
	if (m_Soldier->flagPower())
	{
		// OH SHIT, YO TENGO LA BANDERA VAMANOS A LA CHINGADA.
		m_Soldier->m_fsm.SetState(BOIDSTATE::kToBase);
		return 0;
	}

	if (m_Soldier->enemyInSight() != nullptr)
	{
		//OH SHIT, UN ENEMIGO TENGO QUE REVENTARLO
		m_Soldier->m_fsm.SetState(BOIDSTATE::kAttackEnemy);
		return 0;
	}

	CSoldier* leader = m_Soldier->leaderInSight();
	if (leader != nullptr)
	{
		// OH SHIT, AHI VA EL LIDER, HAY QUE PROTEGERLO
		m_Soldier->m_fsm.SetState(BOIDSTATE::kDefendLeader);
		return 0;
	}
	else
	{
		// HMM... ¿ENTONCES QUE HAGO?
		float decision = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		if (decision <= 0.5f)
		{
			m_Soldier->m_fsm.SetState(BOIDSTATE::kAttack);
			return 0;
		}
		else {
			m_Soldier->m_fsm.SetState(BOIDSTATE::kDefendBase);
			return 0;
		}		
	}	
	return 0;	
}

void CIdle::onExit()
{

}

CIdle::CIdle(CSoldier* mySoldier) : CBoidState(BOIDSTATE::kIdle, mySoldier)
{

}


CIdle::~CIdle()
{
}
