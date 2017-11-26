#include "stdafx.h"
#include "DefendLeader.h"
#include "GameScene.h"
#include "Soldier.h"

void CDefendLeader::onEnter()
{
	m_Soldier->m_stateDebug = "Defend Leader";
}

unsigned int CDefendLeader::update(void * pObject)
{
	// SIGUE AL LIDER
	CSoldier* leader = m_Soldier->leaderInSight();
	if (leader != nullptr)
	{		
		//SEGUIR AL LIDER
		m_Soldier->addNewTarget(leader, BOIDTARGET::kLeader);
	}
	else
	{		
		// HE PERDIDO AL LIDER
		m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
	}

	return 0;
}

void CDefendLeader::onExit()
{	
	m_Soldier->removeTarget(BOIDTARGET::kLeader);	
}

CDefendLeader::CDefendLeader(CSoldier * mySoldier) : CBoidState(BOIDSTATE::kDefendLeader, mySoldier)
{
}


CDefendLeader::~CDefendLeader()
{
}
