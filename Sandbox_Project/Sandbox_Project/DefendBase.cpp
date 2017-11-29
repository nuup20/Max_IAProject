#include "stdafx.h"
#include "Soldier.h"
#include "DefendBase.h"
#include "Base.h"

CDefendBase::CDefendBase(CSoldier* mySoldier) : CBoidState(BOIDSTATE::kDefendBase,mySoldier)
{	
}

void CDefendBase::onEnter()
{
	m_Soldier->m_stateDebug = "Defend Base";
}

unsigned int CDefendBase::update(void * pObject)
{
	CFlag* enemyFlag = m_Soldier->enemyFlagInSight();
	if (enemyFlag != nullptr)
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kAttack);
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
		m_Soldier->m_fsm.SetState(BOIDSTATE::kDefendLeader);
		return 0;
	}

	CVector3 vectToBase = ((m_Soldier->friendlyBase())->m_position - m_Soldier->m_position);
	if (vectToBase.magnitud() >= static_cast<float>(DEFENCE_RANGE))
	{
		//HE SALIDO DEL RANGO RANGO DE DEFENSA.
		m_Soldier->addNewTarget(m_Soldier->friendlyBase(), BOIDTARGET::kSeek);
		m_Soldier->setWander(false);
		return 0;
	}
	else {
		//VIGILAR
		m_Soldier->removeTarget(BOIDTARGET::kSeek);
		m_Soldier->setWander(true);
		return 0;
	}
	return 0;
}

void CDefendBase::onExit()
{
	m_Soldier->removeTarget(BOIDTARGET::kSeek);
	m_Soldier->setWander(false);
}

CDefendBase::~CDefendBase()
{
}
