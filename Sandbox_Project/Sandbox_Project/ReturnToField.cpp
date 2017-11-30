#include "stdafx.h"
#include "ReturnToField.h"
#include "Soldier.h"
#include "Base.h"

void CReturnToField::onEnter()
{
	m_Soldier->m_stateDebug = "Return To Field";
	if (m_Soldier->flagPower())
	{
		m_Soldier->addNewTarget(m_Soldier->friendlyBase(), BOIDTARGET::kSeek);
	}
	else
	{
		m_Soldier->addNewTarget(&m_center, BOIDTARGET::kSeek);
	}
	
}

unsigned int CReturnToField::update(void * pObject)
{
	if (!m_Soldier->outOfField())
	{
		m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
	}
	return 0;
}

void CReturnToField::onExit()
{
	m_Soldier->removeTarget(BOIDTARGET::kSeek);
}

CReturnToField::CReturnToField(CSoldier * mySoldier) : CBoidState(BOIDSTATE::kToField, mySoldier)
{
	m_center.setPosition(960, 540);
}

CReturnToField::~CReturnToField()
{
}
