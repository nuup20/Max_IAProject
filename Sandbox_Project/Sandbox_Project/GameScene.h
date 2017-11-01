#pragma once
#include "Scene.h"
#include  "World.h"

namespace GAMEBUTTON {
	enum e {
		kUndefined,
		KSeekAgent,
		kFleeAgent,
		KBack,
		kCount
	};
}

class CGameScene :
	public CScene
{
protected:
	CWorld m_world;
	vector<CInteractiveButton*> m_buttonList;
	CBoid* m_activeAgent;

	virtual void buttonFunc(int id);
	virtual void setButtonPositions();

public:	

	virtual void	onEnter();
	virtual void	onExit();

	virtual void init();	
	virtual unsigned int update(void* pObject);
	virtual void render(RenderWindow& wnd);
	virtual void destroy();

	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	CGameScene(int sceneID, const std::string& title, RenderWindow* window) : CScene(sceneID, title, window) {}
	virtual ~CGameScene();
};

