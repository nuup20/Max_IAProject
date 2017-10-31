#pragma once
#include "GameScene.h"
class CSeekScreen :
	public CGameScene
{
private:

public:

	void init();

	CSeekScreen(const std::string& title, RenderWindow* window) : CGameScene(SCENE_STATES::kSeekScene, title, window) {}
	~CSeekScreen() { destroy(); }
};

