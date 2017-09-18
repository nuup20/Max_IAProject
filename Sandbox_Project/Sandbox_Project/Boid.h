#pragma once
#include <vector>
#include "GameObject.h"
#include "Vector3.h"
#include "SFML\Graphics.hpp"

using sf::CircleShape;
using sf::RenderWindow;
using std::vector;

class CBoid : public CGameObject
{
private:
	CircleShape m_shape;	
public:

	CVector3	m_direction;	
	
	vector<CVector3>	nodes;
	int					pathIndex;

	void		init();
	void		update();
	void		render(RenderWindow& wnd);
	void		destroy();

	CVector3	seek(int x, int y);
	CVector3	flee(int x, int y);
	CVector3	arrive(int x, int y);
	CVector3	pursuit(CVector3 pos, CVector3 dir, float speed);
	CVector3	evade(CVector3 pos, CVector3 dir, float speed);
	CVector3	wander();
	CVector3	followPath();
	CVector3	followPath(vector<CVector3>& nodeList, float index);

	void		setDirection(int x, int y);
	void		setShapeColor(int r, int g, int b, int a);
	void		setPathIndex(int index);
	void		transform();

	CBoid();
	~CBoid();
};

