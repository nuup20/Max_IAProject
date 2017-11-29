#pragma once
#include "RendObject.h"

class CGameScene;
class CBullet :
	public CRendObject
{
private:
	CGameScene* m_gmScn;

public:
	void init();	
	void update();
	void render(RenderWindow& wnd);
	void destroy();
	
	unsigned int		m_team;
	CVector3			m_direction;

	static const int	BULLET_RADIUS = 15;
	static const int	BULLET_SPEED = 400;

	CBullet(CVector3& position, CVector3& direction, CGameScene* gmscn, unsigned int team = TEAM::kUndefined);
	~CBullet();
};

