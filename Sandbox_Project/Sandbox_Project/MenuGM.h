#pragma once
#include "PureMenuScene.h"

class CMenuGM : 
	public CPureMenuScene
{
private:
	void	buttonFunc(unsigned int index);

public:
	void init();
	
	CMenuGM(const std::string& title, RenderWindow* window) : CPureMenuScene(SCENE_STATES::kMenu, title, window) { m_font.loadFromFile("fonts/Keep_Singing.ttf"); }
	~CMenuGM() { destroy(); }
};

