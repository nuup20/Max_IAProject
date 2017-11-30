#pragma once
#include "RendObject.h"

using sf::CircleShape;

class CObstacle : public CRendObject
{
private:
	CircleShape m_ObstacleCol;
	bool		m_debug;

public:
	float	m_radius;

	void init();
	void render(RenderWindow& wnd);
	void update();
	void setRadius(float radius);
	void setDebug();

	CObstacle();
	~CObstacle();
};

