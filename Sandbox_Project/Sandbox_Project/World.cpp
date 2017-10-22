#include "stdafx.h"
#include "World.h"


void CWorld::init()
{
	//CREATE OBSTACLE
	CRendObject* _newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Objective";
	_newR->setPosition(520, 350);	
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_crusier.png");
	//_newR->scale(0.5f);
	m_gameObjectList.push_back(_newR);

	//CREATE AGENT
	CBoid* _newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(100, 500);
	_newGO->m_direction = CVector3(0.0f, -1.0f, 0.0f);
	_newGO->scaleSprite(0.8f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_plane.png");
	m_gameObjectList.push_back(_newGO);	
	_newGO->setObjective(_newR);
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
