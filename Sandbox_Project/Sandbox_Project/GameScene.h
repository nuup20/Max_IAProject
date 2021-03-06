#pragma once
#include "Scene.h"
#include  "World.h"

namespace GAMEBUTTON {
	enum e {
		kUndefined,
		KSeekAgent,
		kFleeAgent,
		kWanderAgent,
		kReset,
		kPause,
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

	bool	m_isPaused;

	virtual void buttonFunc(int id);
	virtual void setButtonPositions();

public:	

	virtual void	onEnter();
	virtual void	onExit();

	virtual void init();	
	virtual unsigned int update(void* pObject);
	virtual void render();
	virtual void destroy();

	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);
	void	pauseSystem();
	template <class _obj> vector<_obj*>	getObjsInArea(int x, int y, float radius, unsigned int group = GOGROUP::kEverything);

	CGameScene(int sceneID, const std::string& title, CSFMLWindow* window) : CScene(sceneID, title, window), m_isPaused(false) {}
	virtual ~CGameScene();
};

template<class _obj>
inline vector<_obj*> CGameScene::getObjsInArea(int x, int y, float radius, unsigned int group)
{
	return m_world.getObjsInArea<_obj>(x, y, radius, group);
}
