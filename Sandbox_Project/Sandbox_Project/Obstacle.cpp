#include "stdafx.h"
#include "Obstacle.h"


void CObstacle::init()
{
	m_texture.loadFromFile("textures/default/spr_circle_01.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setColor(Color::White);

	sf::FloatRect rect = m_sprite.getLocalBounds();
	m_sprite.setOrigin(rect.width * 0.5f, rect.height * 0.5f);	
	m_ObstacleCol.setFillColor(sf::Color(255, 0, 0, 120));
}

void CObstacle::render(RenderWindow & wnd)
{
	if (m_isVisible)
	{
		wnd.draw(m_sprite);
	}
	if (m_debug)
	{
		wnd.draw(m_ObstacleCol);
	}
}

void CObstacle::update()
{
	m_sprite.setPosition(m_position.x, m_position.y);
	m_ObstacleCol.setPosition(m_position.x, m_position.y);
}

void CObstacle::setRadius(float radius)
{
	m_radius = radius;
	m_ObstacleCol.setRadius(radius);
	sf::FloatRect obsRect = m_ObstacleCol.getLocalBounds();
	m_ObstacleCol.setOrigin(obsRect.width * 0.5f, obsRect.height * 0.5f);
}

void CObstacle::setDebug()
{
	m_debug = !m_debug;
}

CObstacle::CObstacle() : CRendObject(GOGROUP::kObstacle) , m_radius(1.0f), m_debug(false)
{
	m_name = "Obstacle";
	init();
}


CObstacle::~CObstacle()
{
}
