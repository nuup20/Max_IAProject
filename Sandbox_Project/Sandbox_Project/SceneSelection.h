#pragma once
#include "PureMenuScene.h"

class CSceneSelection :
	public CPureMenuScene
{
	void buttonFunc(unsigned int id);
	void setButtonPositions();

public:
	void init();	

	CSceneSelection(const std::string& title, CSFMLWindow* window) : CPureMenuScene(SCENE_STATES::kSceneSelection, title, window) {
		m_font.loadFromFile("fonts/Keep_Singing.ttf");
	}
	~CSceneSelection() { destroy(); }
};

