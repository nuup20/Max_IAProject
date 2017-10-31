#include "stdafx.h"
#include "World.h"


void CWorld::init()
{

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

void CWorld::addGameObject(CGameObject * newGameObject)
{	
	for (int i = 0; i < m_gameObjectList.size(); ++i) {
		if (newGameObject->m_layer < m_gameObjectList[i]->m_layer) {
			m_gameObjectList.insert(m_gameObjectList.begin() + i, newGameObject);
			return;
		}
	}	
	m_gameObjectList.push_back(newGameObject);
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
