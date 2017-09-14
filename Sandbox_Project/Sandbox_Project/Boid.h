#pragma once
#include "GameObject.h"
#include "Vector3.h"
#include "SFML\Graphics.hpp"

using sf::CircleShape;
using sf::RenderWindow;

class CBoid : public CGameObject
{

private:
	
	CircleShape m_shape;

public:

	void	init();
	void	update();
	void	render(RenderWindow& wnd);
	void	destroy();

	CVector3	seek();
	CVector3	flee();
	CVector3	arrive();
	CVector3	pursuit();
	CVector3	evade();
	CVector3	wander();

	CBoid();
	~CBoid();
};

