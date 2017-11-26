#include "stdafx.h"
#include "Idle.h"
#include "Soldier.h"
#include "Fsm.h"

void CIdle::onEnter()
{

}

unsigned int CIdle::update(void * pObject)
{
	if (m_Soldier->flagPower())
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kToBase);
	}

	CSoldier* leader = m_Soldier->leaderInSight();
	if (leader != nullptr)
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kDefendLeader);
	}
	else
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kAttack);
	}	
	return 0;

	//NO EST� SIGUIENDO AL LIDER ... DEBER�A DE REVISAR SI LA FUNCI�N DE DETECCI�N EST� FUNCIONANDO.
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
