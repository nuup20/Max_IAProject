#include "stdafx.h"
#include "World.h"


void CWorld::init()
{
	//CREATE AGENT
	CBoid* _newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(100, 500);
	_newGO->m_direction = CVector3(0.0f, -1.0f, 0.0f);
	_newGO->setShapeColor(0, 0, 255, 255);
	m_gameObjectList.push_back(_newGO);	
}

void CWorld::update()
{
	for (m_objIt = m_gameObjectList.begin(); m_objIt != m_gameObjectList.end(); ++m_objIt)
		(*m_objIt)->update();
}

void CWorld::render()
{
}

void CWorld::render(RenderWindow& wnd)
{
	for (m_objIt = m_gameObjectList.begin(); m_objIt != m_gameObjectList.end(); ++m_objIt)
		(*m_objIt)->render(wnd);
}

void CWorld::destroy()
{
	for (m_objIt = m_gameObjectList.begin(); m_objIt != m_gameObjectList.end(); ++m_objIt)
		(*m_objIt)->destroy();
}

vector<CGameObject*> CWorld::getObjsInArea(int x, int y, float radius)
{
	CVector3 position(x,y);
	vector<CGameObject*> objectsDetected;
	for (unsigned int i = 0; i < m_gameObjectList.size(); ++i)
		if ((position - m_gameObjectList[i]->m_position).magnitud() <= radius)
			objectsDetected.push_back(m_gameObjectList[i]);
	return objectsDetected;
}

CWorld::CWorld()
{
}

CWorld::~CWorld()
{
	destroy();
}
