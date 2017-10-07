#pragma once
#include <vector>
#include "GameObject.h"
#include "Obstacle.h"
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
	
	vector<CGameObject*>	nodes;
	int						pathIndex;

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
	CVector3	followPath(vector<CGameObject*>& nodeList, float index);
	CVector3	obstacleAvoidance(vector<CObstacle*>& obstacles);
	CVector3	avargeDirection(vector<CBoid*>& boidList);
	CVector3	cohesion(vector<CBoid*>& boidList);
	CVector3	separation(vector<CBoid*>& boidList);
	CVector3	flock(vector<CBoid*>& boidList);
	CVector3	followTheLeader(CBoid& leader, float proyectionMgn, vector<CBoid*>& boidList);

	void		setDirection(int x, int y);
	void		setShapeColor(int r, int g, int b, int a);
	void		addObstacleNode(CGameObject& newNode);
	void		transform();

	CBoid();
	~CBoid();
};

