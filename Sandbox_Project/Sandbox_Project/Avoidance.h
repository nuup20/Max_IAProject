#pragma once
#include "GameScene.h"
class CAvoidance :
	public CGameScene
{
private:
	void buttonFunc(int id);

public:
	void init();

	CAvoidance(const std::string& title, CSFMLWindow* window) : CGameScene(SCENE_STATES::kAvoidance, title, window) {}
	~CAvoidance();
};

