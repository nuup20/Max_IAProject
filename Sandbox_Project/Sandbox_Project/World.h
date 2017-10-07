#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Boid.h"

using std::vector;
using sf::RenderWindow;
using sf::Keyboard;

class CWorld
{
private:

	vector<CGameObject*>				m_gameObjectList;
	vector<CGameObject*>::iterator		m_objIt;

public:

	void	init();
	void	update();
	void	render();
	void	render(RenderWindow& wnd);
	void	destroy();	

	vector<CGameObject*> getObjsInArea(int x, int y, float radius);

	CWorld();
	~CWorld();
};

