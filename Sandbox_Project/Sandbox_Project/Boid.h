#pragma once
#include <vector>
#include "GameObject.h"
#include "Obstacle.h"
#include "Vector3.h"
#include "Fsm.h"
#include "SFML\Graphics.hpp"
#include "WindowTime.h"

using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using std::vector;

namespace BOIDTARGET {
	enum t {
		kUndefined,
		kSeek,
		kFlee,
		kArrive,
		kPursuit,
		kEvade,
		kCount
	};
}

class CBoid : public CGameObject
{
private:
	// Componentes para dibujar el Sprite en SFML
	Texture		m_texture;
	Sprite		m_sprite;
	
	// Vectores para calcular fuerzas y posición
	CVector3				m_direction;
	float					m_velocity;
	CVector3				m_steeringForce;
	CWindowTime				m_wndTime;

	// Objetos necesarios para que funcionen algunos Steering Behaviors
	vector<CGameObject*>	m_targetList;		//
	vector<CGameObject*>	m_nodes;			// --> followPath
	int						m_pathIndex;		// --> followPath
	bool					m_isWander;

public:
	void		init();
	void		update();
	void		render(RenderWindow& wnd);
	void		destroy();

	CVector3	seek(float x, float y);
	CVector3	seek();
	CVector3	flee(float x, float y);
	CVector3	flee();
	CVector3	arrive(float x, float y);
	CVector3	arrive();
	CVector3	pursuit(CVector3 position, CVector3 directeion, float speed);
	CVector3	pursuit();
	CVector3	evade(CVector3 position, CVector3 directeion, float speed);
	CVector3	evade();
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
	void		setVelocity(float vel);
	float		getVelocity();
	void		setSpriteDirectory(string directory);
	void		setSpriteColor(int r, int g, int b, int a);
	void		scaleSprite(float scale);
	void		addObstacleNode(CGameObject& newNode);	
	void		setSteeringForce(CVector3 force);

	bool		addNewTarget(CGameObject* go, unsigned int targetType, bool _deleteGO = false);
	bool		removeTarget(unsigned int targetType, bool _deleteGO = false);
	void		setWander(bool b);
	CVector3	getTargetPosition(unsigned int targetIndex);

	static const int SEEK_FORCE = 150;
	static const int PURSUIT_FORCE = 200;

	CBoid();
	~CBoid();
};

