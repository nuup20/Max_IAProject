#pragma once
#include "Scene.h"
#include  "World.h"

class CGameScene :
	public CScene
{
private:

	CWorld m_world;

public:

	void init();
	void update();
	void render(RenderWindow& wnd);
	void destroy();

	void onMouseClick(int x, int y, short btn);
	void onMouseMove(int x, int y);

	CGameScene();
	~CGameScene();
};

