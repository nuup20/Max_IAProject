#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

using sf::Color;
using sf::Sprite;
using sf::Texture;

class CRendObject :
	public CGameObject
{

	Texture m_texture;
	Sprite	m_sprite;

public:

	void init();
	void render(RenderWindow& wnd);
	void update();
	void destroy();

	void setSpriteDirectory(string directory);
	void setColor(float r,float g,float b,float a);
	void scale(float scalation);

	CRendObject();
	~CRendObject();
};

