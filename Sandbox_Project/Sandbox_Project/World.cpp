#include "stdafx.h"
#include "World.h"


void CWorld::init()
{
}

void CWorld::update()
{
	if (Keyboard::isKeyPressed(Keyboard::C))
		createGameObj();

	for (m_objIt = m_gameObjectList.begin(); m_objIt != m_gameObjectList.end(); ++m_objIt)
		(*m_objIt)->update();
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

void CWorld::createGameObj()
{
	CBoid* newObject = new CBoid;
	newObject->init();
	m_gameObjectList.push_back(newObject);
}

CWorld::CWorld()
{
}


CWorld::~CWorld()
{
	destroy();
}
