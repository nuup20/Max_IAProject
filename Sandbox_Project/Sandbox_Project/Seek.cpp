#include "stdafx.h"
#include "Seek.h"
#include "Boid.h"

void CSeek::onEnter()
{
}

unsigned int CSeek::update(void * pObject)
{
	CVector3 objPos = m_Boid->getObjectivePosition();	
	m_Boid->setSteeringForce(m_Boid->seek(objPos.x, objPos.y));
	return 1;
}

void CSeek::onExit()
{
	m_Boid->setSteeringForce(CVector3(0,0,0));
}

CSeek::~CSeek()
{
}
