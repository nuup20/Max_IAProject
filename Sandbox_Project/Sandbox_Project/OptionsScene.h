#pragma once
#include "PureMenuScene.h"

class COptionsScene :
	public CPureMenuScene
{
private:	

	void buttonFunc(unsigned int id);

public:

	void init();	

	COptionsScene(const std::string& title, RenderWindow* window) : CPureMenuScene(SCENE_STATES ::kOptions, title, window) { m_font.loadFromFile("fonts/Keep_Singing.ttf"); }
	~COptionsScene();
};

