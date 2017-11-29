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
		KDebug,
		kCount
	};
}

class CGameScene :
	public CScene
{
protected:
	CWorld m_world;
	CBoid* m_activeAgent;

	bool	m_isPaused;
	unsigned int m_redScore;
	unsigned int m_redMarks;
	unsigned int m_greenScore;
	unsigned int m_greenMarks;

	Font	m_scoreFont;
	Text	m_redScoreText;
	Text	m_greenScoreText;
	Text	m_redMarkText;
	Text	m_greenMarkText;

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
	void		 pauseSystem();
	bool		 destroyObject(CGameObject* obj);
	void		 addNewObject(CGameObject* obj);
	void		 addPoint(unsigned int team, unsigned int points = 1);
	void		 addDeathMan(unsigned int team);
	template <class _obj> vector<_obj*>	getObjsInArea(int x, int y, float radius, unsigned int group = GOGROUP::kEverything);
	template <class _obj> vector<_obj*> getObjs(unsigned int group = GOGROUP::kEverything);

	CGameScene(int sceneID, const std::string& title, CSFMLWindow* window, CSFMLApplication* app) : CScene(sceneID, title, window, app), m_isPaused(false) {}
	virtual ~CGameScene();
};

template<class _obj>
inline vector<_obj*> CGameScene::getObjsInArea(int x, int y, float radius, unsigned int group)
{
	return m_world.getObjsInArea<_obj>(x, y, radius, group);
}

template<class _obj>
inline vector<_obj*> CGameScene::getObjs(unsigned int group)
{
	return m_world.getObjs<_obj>(group);
}
