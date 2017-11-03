#pragma once
#include "GameScene.h"
class CSeekScreen :
	public CGameScene
{
private:
	void buttonFunc(int id);

public:

	void init();

	CSeekScreen(const std::string& title, CSFMLWindow* window) : CGameScene(SCENE_STATES::kSeekScene, title, window) {}
	~CSeekScreen() { destroy(); }
};

