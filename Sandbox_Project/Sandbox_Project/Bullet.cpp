#include "stdafx.h"
#include "Bullet.h"
#include "GameScene.h"
#include "Obstacle.h"

void CBullet::init()
{
	setSpriteDirectory("gameResources/sprites/" + static_cast<string>((m_team == TEAM::kRed ? "spr_redBullet.png":"spr_greenBullet.png")));
	m_direction.normalize();
}

void CBullet::update()
{
	//MOVE BULLET 
	m_position += m_direction * BULLET_SPEED * m_gmScn->m_time.getFrameTime();
	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setRotation(m_direction.degAngle());
	
	//CHECK FOR OBSTACLES
	vector<CObstacle*> obs = m_gmScn->getObjsInArea<CObstacle>(m_position.x, m_position.y, 200);
	for (auto obstacle : obs)
	{
		CVector3 distToObs = obstacle->m_position - m_position;
		if ((distToObs.magnitud() - (obstacle->m_radius * 0.5)) <= BULLET_RADIUS) 
		{
			//DESTRUIR OBJETO
			m_gmScn->destroyObject(this);
			return;
		}				
	}

	// SI SALE DEL CAMPO DE BATALLA, MUERE.
	if (m_position.x < 0 || m_position.x > 1920 || m_position.y < 0 || m_position.y > 1080)
	{
		m_gmScn->destroyObject(this);
		return;
	}
	return;
}

void CBullet::render(RenderWindow & wnd)
{
	if (m_isVisible) {
		wnd.draw(m_sprite);
	}
}

void CBullet::destroy()
{

}

CBullet::CBullet(CVector3& position, CVector3 & direction, CGameScene* gmscn, unsigned int team) : CRendObject(GOGROUP::kBullet), m_team(team)
	 , m_direction(direction), m_gmScn(gmscn)
{
	m_name = "Bullet";
	m_position = position;
	init();
}

CBullet::~CBullet()
{
}
