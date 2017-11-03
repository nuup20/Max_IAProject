#include "stdafx.h"
#include "Evade.h"
#include "Boid.h"
void CEvade::onEnter()
{
}

unsigned int CEvade::update(void * pObject)
{	
	m_Boid->setSteeringForce(m_Boid->evade());
	return 1;
}

void CEvade::onExit()
{
	m_Boid->setSteeringForce(CVector3(0, 0, 0));
}

CEvade::~CEvade()
{

}
