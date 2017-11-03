#pragma once
#include "GameScene.h"
class CPursuitScreen :
	public CGameScene
{
private:
	void buttonFunc(int id);

public:
	void init();

	CPursuitScreen(const std::string& title, CSFMLWindow* window) : CGameScene(SCENE_STATES::kPursuitScn, title, window) {}
	~CPursuitScreen();
};

