#include "stdafx.h"
#include "Dead.h"
#include "GameScene.h"
#include "Soldier.h"

void CDead::onEnter()
{
	m_timeCount = 0;	
	
}

unsigned int CDead::update(void * pObject)
{
	m_Soldier->m_position = CVector3(-300, -300);
	CGameScene* gmScn = reinterpret_cast<CGameScene*>(pObject);
	m_timeCount += gmScn->m_time.getFrameTime();

	if (m_Soldier->m_isEnable)
	{
		m_Soldier->m_isEnable = false;
		gmScn->addDeathMan(m_Soldier->soldierTeam());
	}
	

	if (m_Soldier->flagPower()) {
		vector<CFlag*> flags = gmScn->getObjs<CFlag>();

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
		m_Soldier->setFlagPower(false);
	}	

	if (m_timeCount >= m_timeToRespawn)
	{
		m_Soldier->m_position = m_Soldier->m_respawnPosition;
		m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
		return 0;
	}
	return 0;
}

void CDead::onExit()
{
	m_Soldier->m_isEnable = true;
	m_Soldier->m_direction = CVector3(m_Soldier->soldierTeam() == TEAM::kRed ? 1 : -1, 0);
}

CDead::CDead(CSoldier * mySoldier) : CBoidState(BOIDSTATE::kDead,mySoldier)
{

}

CDead::~CDead()
{
}
