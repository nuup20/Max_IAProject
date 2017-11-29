#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Boid.h"
#include "RendObject.h"
#include "InteractiveButton.h"

using std::vector;
using sf::RenderWindow;
using sf::Keyboard;

class CWorld
{
private:

	vector<CGameObject*>				m_gameObjectList;
	vector<CGameObject*>				m_obsToAdd;
	vector<CGameObject*>				m_obsToDelete;
	vector<CGameObject*>::iterator		m_objIt;

	void	addGOsInList();
	void	removeGOsInList();

public:

	void	init();
	void	update();
	void	render();
	void	render(RenderWindow& wnd);
	void	destroy();	

	void		addGameObject(CGameObject* newGameObject);
	bool		destroyGameObject(CGameObject* gameObject);
	template <class _obj> vector<_obj*>	getObjsInArea(int x, int y, float radius, unsigned int m_group = GOGROUP::kEverything);
	template <class _obj> vector<_obj*> getObjs(unsigned int m_group = GOGROUP::kEverything);
	void		localTranslation(int x, int y);
	void		cleanWorld();

	CWorld();
	~CWorld();
};

template<class _obj>
inline vector<_obj*> CWorld::getObjsInArea(int x, int y, float radius, unsigned int m_group)
{
	CVector3 position((float)x, (float)y);
	vector<_obj*> objectsDetected;	

	for (unsigned int i = 0; i < m_gameObjectList.size(); ++i) {
		if ((position - m_gameObjectList[i]->m_position).magnitud() <= radius)
		{
			_obj* object = dynamic_cast<_obj*>(m_gameObjectList[i]);
			if (object)
			{
				if (m_gameObjectList[i]->m_group == m_group || m_group == GOGROUP::kEverything)
				{
					objectsDetected.push_back(object);
				}
			}
		}
	}
	return objectsDetected;
}

template<class _obj>
inline vector<_obj*> CWorld::getObjs(unsigned int m_group)
{
	vector<_obj*> objects;
	for (unsigned int i = 0; i < m_gameObjectList.size(); ++i)
	{
		_obj* object = dynamic_cast<_obj*>(m_gameObjectList[i]);
		if (object)
		{
			if (m_gameObjectList[i]->m_group == m_group || m_group == GOGROUP::kEverything)
			{
				objects.push_back(object);
			}
		}
	}
	return objects;
}
