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
		delete *m_objIt;
	m_gameObjectList.clear();
}

void CWorld::addGameObject(CGameObject * newGameObject)
{	
	for (unsigned int i = 0; i < m_gameObjectList.size(); ++i) {
		if (newGameObject->m_layer < m_gameObjectList[i]->m_layer) {
			m_gameObjectList.insert(m_gameObjectList.begin() + i, newGameObject);
			return;
		}
	}	
	m_gameObjectList.push_back(newGameObject);
}

void CWorld::localTranslation(int x, int y)
{
	for (int i = 0; i < m_gameObjectList.size(); ++i)
	{
		m_gameObjectList[i]->m_position.x += x;
		m_gameObjectList[i]->m_position.y += y;
	}
}

CWorld::CWorld()
{
}

CWorld::~CWorld()
{
	destroy();
}
