#include "stdafx.h"
#include "Flee.h"
#include "Boid.h"

void CFlee::onEnter()
{
}

unsigned int CFlee::update(void * pObject)
{
	CVector3 objPos = m_Boid->getObjectivePosition();
	m_Boid->setSteeringForce(m_Boid->flee(objPos.x, objPos.y));
	return 1;
}

void CFlee::onExit()
{
	m_Boid->setSteeringForce(CVector3(0, 0, 0));
}

CFlee::~CFlee()
{
}
