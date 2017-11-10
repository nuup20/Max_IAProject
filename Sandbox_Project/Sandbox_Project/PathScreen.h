#pragma once
#include "GameScene.h"
class CPathScreen :
	public CGameScene
{
private:
	void buttonFunc(int id);

public:
	void init();

	CPathScreen(const std::string& title, CSFMLWindow* window) : CGameScene(SCENE_STATES::kPathScene, title, window) {}
	~CPathScreen();
};

