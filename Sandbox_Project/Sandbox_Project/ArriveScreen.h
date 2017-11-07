#pragma once
#include "GameScene.h"
class CArriveScreen :
	public CGameScene
{
private:
	void buttonFunc(int id);
	
public:
	void init();

	CArriveScreen(const std::string& title, CSFMLWindow* window) : CGameScene(SCENE_STATES::kArriveScene, title, window) {}
	~CArriveScreen();
};

