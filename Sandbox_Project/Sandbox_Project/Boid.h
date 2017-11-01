#pragma once
#include <vector>
#include "GameObject.h"
#include "Obstacle.h"
#include "Vector3.h"
#include "Fsm.h"
#include "SFML\Graphics.hpp"

#include "Seek.h"
#include "Flee.h"

using sf::CircleShape;
using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using std::vector;

class CBoid : public CGameObject
{
private:
	Texture		m_texture;
	Sprite		m_sprite;

	CFsm		m_Fsm;
	CState*		m_activeState;	
	
	CVector3				m_direction;
	CVector3				m_steeringForce;
	CGameObject*			m_Objective;	
	vector<CGameObject*>	m_nodes;
	int						m_pathIndex;

public:
	void		init();
	void		update();
	void		render(RenderWindow& wnd);
	void		destroy();

	CVector3	seek(float x, float y);
	CVector3	flee(float x, float y);
	CVector3	arrive(float x, float y);
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

	void		setDirection(float x, float y, float z = 0);
	CVector3	getDirection();
	void		setSpriteDirectory(string directory);
	void		setSpriteColor(int r, int g, int b, int a);
	void		scaleSprite(float scale);
	void		addObstacleNode(CGameObject& newNode);
	void		setObjective(CGameObject* newObj);
	CVector3	getObjectivePosition();
	void		setSteeringForce(CVector3 force);

	bool		setActiveState(int id);

	CBoid();
	~CBoid();
};

