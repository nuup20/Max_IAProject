#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>

using sf::Color;
using sf::Sprite;
using sf::Texture;

class CRendObject :
	public CGameObject
{
protected:
	Texture m_texture;
	Sprite	m_sprite;	

public:

	virtual void init();
	virtual void render(RenderWindow& wnd);
	virtual void update();
	virtual void destroy();

	void setSpriteDirectory(string directory);
	void setColor(float r,float g,float b,float a);
	void scale(float scalation);

	bool	m_isVisible;

	CRendObject(unsigned int group = GOGROUP::kUndefined);
	virtual ~CRendObject();
};

