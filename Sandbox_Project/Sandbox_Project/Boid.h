#pragma once
#include <vector>
#include "RendObject.h"
#include "Fsm.h"
#include "SFML\Graphics.hpp"

using sf::RenderWindow;
using sf::Texture;
using sf::Sprite;
using sf::Vertex;
using sf::CircleShape;
using sf::Vector2f;
using sf::Font;
using sf::Text;
using std::vector;
using std::to_string;

namespace BOIDTARGET {
	enum t {
		kUndefined,
		kSeek,
		kFlee,
		kArrive,
		kPursuit,
		kEvade,
		kLeader,		
		kCount
	};
}

class CVector3;
class CGameScene;
class CObstacle;
class CAttack;
class CIdle;
class CToBase;

class CBoid : public CRendObject
{
	friend class CAttack;
	friend class CIdle;
	friend class CToBase;
	friend class CDefendLeader;
	friend class CDefendBase;
	friend class CAttackEnemy;
	friend class CDead;

protected:	
	CGameScene* m_gameScene;
	CFsm		m_fsm;
	CState*		m_activeState;

	//	Elementos para Debugear
	Font		m_font;
	Text		m_text;	
	CircleShape	m_wanderCircle;
	CVector3	m_wanderForce;
	float		m_timeTrigger;
	float		m_timeCount;
	
	// Vectores para calcular fuerzas y posición
	CVector3				m_direction;
	float					m_velocity;
	float					m_mass;
	CVector3				m_steeringForce;	

	// Objetos necesarios para que funcionen algunos Steering Behaviors
	vector<CGameObject*>	m_targetList;		//
	vector<CGameObject*>	m_nodes;			// --> followPath
	int						m_pathIndex;		// --> followPath
	bool					m_isWander;
	bool					m_isFlocking;
	bool					m_debug;	

	void		drawVector(CVector3 position, CVector3 vector, RenderWindow& wnd, bool scale = false);
	void		drawVectorInfo(RenderWindow& wnd);

public:
	virtual void	init();
	virtual void	update();
	virtual void	render(RenderWindow& wnd);
	virtual void	destroy();

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
	CVector3	defendTheLeader();

	void		setDirection(float x, float y, float z = 0);
	CVector3	getDirection();
	void		setVelocity(float vel);
	float		getVelocity();
	void		setMass(float mas);	
	void		setDebug();
	void		addPathNode(CGameObject* newNode);	
	void		setSteeringForce(CVector3 force);	

	bool		addNewTarget(CGameObject* go, unsigned int targetType, bool _deleteGO = false);
	bool		removeTarget(unsigned int targetType, bool _deleteGO = false);
	void		setWander(bool b);
	void		setFlocking(bool b);
	CVector3	getTargetPosition(unsigned int targetIndex);

	static const int SEEK_FORCE = 150;
	static const int PURSUIT_FORCE = 200;
	static const int BOID_RADIUS = 25;
	static const int BOID_VISION = 275;

	string		m_stateDebug;

	CBoid(CGameScene* gmScn);
	virtual ~CBoid();
};

