#pragma once
#include "PureMenuScene.h"

class CMenuGM : 
	public CPureMenuScene
{
private:
	Texture				m_titleTexture;
	Sprite				m_titleSprite;

	void	buttonFunc(unsigned int index);

public:

	void init();
	void render();
	
	CMenuGM(const std::string& title, CSFMLWindow* window, CSFMLApplication* app) : CPureMenuScene(SCENE_STATES::kMenu, title, window, app) { m_font.loadFromFile("fonts/Keep_Singing.ttf"); }
	~CMenuGM() { destroy(); }
};

