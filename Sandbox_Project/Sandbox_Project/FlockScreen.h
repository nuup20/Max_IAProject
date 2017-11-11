#pragma once
#include "GameScene.h"
class CFlockScreen :
	public CGameScene
{
private:
	void buttonFunc(int id);

public:
	void init();

	CFlockScreen(const std::string& title, CSFMLWindow* window) : CGameScene(SCENE_STATES::kFlock, title, window) {}
	~CFlockScreen();
};

