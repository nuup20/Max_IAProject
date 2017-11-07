#pragma once
#include "GameScene.h"


class CWanderScreen :
	public CGameScene
{
private:
	void buttonFunc(int id);
	vector<CBoid*> ants;
	CGameObject*		m_colony;

public:
	void init();
	void destroy();

	CWanderScreen(const std::string& title, CSFMLWindow* window) : CGameScene(SCENE_STATES::kWanderScn, title, window) {}
	~CWanderScreen();
};

