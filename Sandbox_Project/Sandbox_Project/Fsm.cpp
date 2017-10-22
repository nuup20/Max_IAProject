#include "stdafx.h"
#include "Fsm.h"


void CFsm::AddState(CState * pState, bool deleteOnExit)
{
	if (pState)
	{
		m_stateList.push_back(pState);
		pState->SetFSM(this);
	}
}

int CFsm::SetState(unsigned int s)
{
	for (auto& state : m_stateList)
	{
		if (state->m_id == s)
		{
			if (m_aciveState != state) {
				if (m_aciveState != nullptr) {
					m_aciveState->onExit();
				}
				m_aciveState = state;
				m_aciveState->onEnter();
			}
			
			return m_aciveState->m_id;
		}
	}
	
	return 0;	//No se encontro el estado
}

int CFsm::UpdateState(void* pObject)
{
	if (m_aciveState)
	{
		m_aciveState->update(pObject);
	}
	return 0;
}

CFsm::CFsm()
{
	m_aciveState = nullptr;
}


CFsm::~CFsm()
{
	m_aciveState = nullptr;

	for (auto state : m_stateList)
	{
		delete state;
	}

	m_stateList.clear();
}
