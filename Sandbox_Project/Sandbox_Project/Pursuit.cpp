#include "stdafx.h"
#include "Pursuit.h"
#include "Boid.h"

void CPursuit::onEnter()
{

}

unsigned int CPursuit::update(void * pObject)
{	
	m_Boid->setSteeringForce(m_Boid->pursuit());
	return 1;
}

void CPursuit::onExit()
{
	m_Boid->setSteeringForce(CVector3(0, 0, 0));
}

CPursuit::~CPursuit()
{
}
