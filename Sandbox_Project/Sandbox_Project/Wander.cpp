#include "stdafx.h"
#include "Wander.h"
#include "Boid.h"

void CWander::onEnter()
{
}

unsigned int CWander::update(void * pObject)
{	
	m_Boid->setSteeringForce(m_Boid->wander());
	return 1;
}

void CWander::onExit()
{
	m_Boid->setSteeringForce(CVector3(0, 0, 0));
}

CWander::~CWander()
{
}
