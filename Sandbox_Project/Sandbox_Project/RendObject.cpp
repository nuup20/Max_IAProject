#include "stdafx.h"
#include "RendObject.h"


CRendObject::CRendObject()
{
	
}


CRendObject::~CRendObject()
{
	destroy();
}

void CRendObject::init()
{
	m_texture.loadFromFile("textures/default/spr_circle_01.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setColor(Color::Red);

	sf::FloatRect rect = m_sprite.getLocalBounds();
	m_sprite.setOrigin(rect.width * 0.5f, rect.height * 0.5f);
}

void CRendObject::render(RenderWindow & wnd)
{
	wnd.draw(m_sprite);
}

void CRendObject::update()
{	
	m_sprite.setPosition(m_position.x, m_position.y);
}

void CRendObject::destroy()
{
}

void CRendObject::setSpriteDirectory(string directory)
{
	if(!m_texture.loadFromFile(directory))
		m_texture.loadFromFile("textures/default/spr_circle_01.png");
	m_sprite.setTexture(m_texture, true);
	
	sf::FloatRect rect = m_sprite.getLocalBounds();
	m_sprite.setOrigin(rect.width * 0.5f, rect.height * 0.5f);
}

void CRendObject::setColor(float r, float g, float b, float a)
{
	m_sprite.setColor(Color(r, g, b, a));
}

void CRendObject::scale(float scalation)
{
	m_sprite.scale(scalation, scalation);
}
