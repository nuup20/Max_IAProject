#pragma once
#include "Boid.h"
#include "Fsm.h"
#include "Flag.h"

class CGameScene;
class CBase;
class CSoldier :
	public CBoid
{
protected:
	Texture		m_miniFlag_texture;
	Sprite		m_miniFlag_Sprite;

	CFsm		m_stateMchn;
	CBase*		m_enemyBase;
	CBase*		m_friendlyBase;	

	bool		m_flagPower;	

	const float		m_timeToShoot = 0.5f;
	float			m_shootTimeCnt;

	unsigned int	m_team;

public:

	void	init();
	void	update();
	void	render(RenderWindow& wnd);
	void	destroy();

	unsigned int	soldierTeam();
	bool			flagPower();
	bool			outOfField();
	void			setFlagPower(bool setFlag);	

	CBase*		enemyBase();
	CBase*		friendlyBase();	
	CSoldier*	leaderInSight();
	CSoldier*	enemyInSight();
	CFlag*		enemyFlagInSight();
	bool		shootBullet();
	CVector3	sceneLitimsForce();

	bool		m_isMoving;
	CVector3	m_respawnPosition;

	template<class _obj> vector<_obj*> objectsAtVisionRange();
	
	CSoldier(CGameScene* gmScn, unsigned int m_team = TEAM::kGreen);
	~CSoldier();
};

template<class _obj>
inline vector<_obj *> CSoldier::objectsAtVisionRange()
{
	return this->m_gameScene->getObjsInArea<_obj>(m_position.x, m_position.y, BOID_VISION);	
}
