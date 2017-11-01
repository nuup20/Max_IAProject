#pragma once
#include "Scene.h"
#include "InteractiveButton.h"

namespace BUTTONS_MENU {
	enum b {
		kUndefined,
		KSceneSelectionScn,
		kOptionsScn,
		kMenuScn,	
		KSeekFleeScn,
		kCount
	};
}

class CPureMenuScene // SCENA UNICAMENTE CON BOTONES
	: public CScene
{

protected:

	vector<CInteractiveButton*> m_buttonList;
	Font	m_font;
	Text	m_title;

	virtual void buttonFunc(unsigned int id) {}

public:

	virtual void			onEnter();
	virtual unsigned int	update(void* pObject) override;
	virtual void			onExit();

	virtual void init();
	virtual void render(RenderWindow& wnd);
	virtual void destroy();

	virtual void setSceneName(string newName);
	virtual void setTitle(string newTitle);
	virtual void setTitlePostion(short x, short y);
	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	CPureMenuScene(unsigned int id, const std::string& name, RenderWindow* window) : CScene(id, name, window) {}
	virtual ~CPureMenuScene();
};

