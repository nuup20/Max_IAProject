#pragma once
#include <SFML\Graphics.hpp>
#include "Vector3.h"

using sf::RenderWindow;
using std::string;

namespace GOGROUP {
	enum g {
		kUndefined,
		kEverything,
		kObstacle,
		kBoid,
		kFlag,
		kBase,
		kCount
	};
}

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
	unsigned int	m_group;
	CVector3		m_position;
	int				m_layer;

	virtual void	init();
	virtual void	update();
	virtual void	render(RenderWindow& wnd);
	virtual void	destroy();

	void		setPosition(int x, int y);
	void		setName(string name);
	void		setLayer(int layer);
	void		setObjectGroup(unsigned int group);

	CGameObject( unsigned int group = 0) : m_layer(0), m_group(group) {}
	virtual ~CGameObject();
};

