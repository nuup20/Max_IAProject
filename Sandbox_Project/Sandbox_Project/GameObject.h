#pragma once
#include <SFML\Graphics.hpp>
#include "Vector3.h"

using sf::RenderWindow;
using std::string;

class CGameObject
{
public:

	string			m_name;
	CVector3		m_position;

	virtual void	init();
	virtual void	update();
	virtual void	render(RenderWindow& wnd);
	virtual void	destroy();

	CGameObject();
	virtual ~CGameObject();
};

