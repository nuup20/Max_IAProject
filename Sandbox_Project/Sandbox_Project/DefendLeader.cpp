#include "stdafx.h"
#include "DefendLeader.h"
#include "GameScene.h"
#include "Soldier.h"

void CDefendLeader::onEnter()
{

}

unsigned int CDefendLeader::update(void * pObject)
{
	// SIGUE AL LIDER
	CSoldier* leader = m_Soldier->leaderInSight();
	if (leader != nullptr)
	{
		m_Soldier->setForceToDirection(leader->getDirection());
		m_Soldier->addNewTarget(leader, BOIDTARGET::kSeek);
	}
	else
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
	}

	return 0;
}

void CDefendLeader::onExit()
{
	m_Soldier->setForceToDirection(CVector3());
	m_Soldier->removeTarget(BOIDTARGET::kSeek);
}

CDefendLeader::CDefendLeader(CSoldier * mySoldier) : CBoidState(BOIDSTATE::kDefendLeader, mySoldier)
{
}


CDefendLeader::~CDefendLeader()
{
}
