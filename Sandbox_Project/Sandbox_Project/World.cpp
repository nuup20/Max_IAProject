#include "stdafx.h"
#include "World.h"
#include <iostream>

void CWorld::init()
{

}

void CWorld::update()
{
	for (unsigned int i = 0; i < m_obsToDelete.size(); ++i)
	{
		for (unsigned int j = 0; j < m_gameObjectList.size(); ++j)
		{
			if (m_gameObjectList[j] != nullptr)
			{
				if (m_gameObjectList[j] == m_obsToDelete[i]) 
				{
					delete m_gameObjectList[j];
					m_obsToDelete[i] = nullptr;
					m_gameObjectList[j] = nullptr;
					m_gameObjectList.erase(m_gameObjectList.begin() + j);
					break;
				}					
			}
		}
	}
	m_obsToDelete.clear();

	for (unsigned int i = 0; i < m_gameObjectList.size(); ++i)
	{
		if (m_gameObjectList[i] != nullptr) 
		{
			m_gameObjectList[i]->update();
		}		
	}		
}

void CWorld::render()
{
}

void CWorld::render(RenderWindow& wnd)
{
	for (unsigned int i = 0; i < m_gameObjectList.size(); ++i)
	{
		if (m_gameObjectList[i] != nullptr)
		{
			m_gameObjectList[i]->render(wnd);
		}
	}
}

void CWorld::destroy()
{
	for (m_objIt = m_gameObjectList.begin(); m_objIt != m_gameObjectList.end(); ++m_objIt)
	{
		if (*m_objIt != nullptr)
		{
			delete *m_objIt;
		}		
	}		
	m_gameObjectList.clear();
}

void CWorld::addGameObject(CGameObject * newGameObject)
{	
	for (unsigned int i = 0; i < m_gameObjectList.size(); ++i)
	{		
			if (newGameObject->m_layer < m_gameObjectList[i]->m_layer) 
			{
				std::cout << "GO Added: " << newGameObject->m_name << std::endl;
				m_gameObjectList.insert(m_gameObjectList.begin() + i, newGameObject);
				return;
			}		
	}
	std::cout << "GO Added: " << newGameObject->m_name << std::endl;
	m_gameObjectList.push_back(newGameObject);
	return;	
}

bool CWorld::destroyGameObject(CGameObject * gameObject)
{	
	m_obsToDelete.push_back(gameObject);
	return false;
}

void CWorld::localTranslation(int x, int y)
{
	for (int i = 0; i < m_gameObjectList.size(); ++i)
	{
		if (m_gameObjectList[i] != nullptr) {
			m_gameObjectList[i]->m_position.x += x;
			m_gameObjectList[i]->m_position.y += y;
		}		
	}
}

void CWorld::cleanWorld()
{
	
}

CWorld::CWorld()
{
}

CWorld::~CWorld()
{
	destroy();
}
