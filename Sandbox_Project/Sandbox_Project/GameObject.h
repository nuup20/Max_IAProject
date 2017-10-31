#pragma once
#include <SFML\Graphics.hpp>
#include "Vector3.h"

using sf::RenderWindow;
using std::string;

class CObject
{
public:
	CObject() {};
	virtual ~CObject() {};
};

class CGameObject : public CObject
{
public:

	string			m_name;
	CVector3		m_position;
	int				m_layer;

	virtual void	init();
	virtual void	update();
	virtual void	render(RenderWindow& wnd);
	virtual void	destroy();

	void		setPosition(int x, int y);
	void		setName(string name);
	void		setLayer(int layer);

	CGameObject(int layer = 0) : m_layer(layer) {}
	virtual ~CGameObject();
};

