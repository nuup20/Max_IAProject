#pragma once
#include "GameScene.h"

class CFleeScreen :
	public CGameScene
{
public:

	void init();

	CFleeScreen(const std::string& title, RenderWindow* window) : CGameScene(SCENE_STATES::kSeekScene, title, window) {}
	~CFleeScreen() { destroy(); }
};

