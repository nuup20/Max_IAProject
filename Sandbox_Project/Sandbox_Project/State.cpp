#include "stdafx.h"
#include "State.h"


void CState::onEnter()
{
}

unsigned int CState::update(void* pObject)
{
	return 0;
}

void CState::onExit()
{
}

CState::CState() : m_id(0)
{
	
}


CState::~CState()
{
}
