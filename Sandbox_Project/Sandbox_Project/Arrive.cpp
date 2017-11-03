#include "stdafx.h"
#include "Arrive.h"
#include "Boid.h"

void CArrive::onEnter()
{
}

unsigned int CArrive::update(void * pObject)
{
	CVector3 objPos = m_Boid->getObjectivePosition();
	m_Boid->setSteeringForce(m_Boid->arrive(objPos.x, objPos.y));
	return 1;
}

void CArrive::onExit()
{
	m_Boid->setSteeringForce(CVector3(0, 0, 0));
}

CArrive::~CArrive()
{
}
