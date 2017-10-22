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
	unsigned int update(void* pObject);
	void render(RenderWindow& wnd);
	void destroy();

	void onMouseReleased(int x, int y, short btn);
	void onMouseMove(int x, int y);

	CGameScene(const std::string& title, RenderWindow* window) : CScene(SCENE_STATES::kGame, title, window) {}
	~CGameScene();
};

