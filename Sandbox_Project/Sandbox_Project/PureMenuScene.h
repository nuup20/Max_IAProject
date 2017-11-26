#pragma once
#include "Scene.h"
#include "InteractiveButton.h"

namespace BUTTONS_MENU {
	enum b {
		kUndefined,
		kToGame,
		kToMenu,	
		kToOptions,
		kToExit,
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
	virtual void render();
	virtual void destroy();

	virtual void setSceneName(string newName);
	virtual void setTitle(string newTitle);
	virtual void setTitlePostion(short x, short y);
	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	CPureMenuScene(unsigned int id, const std::string& name, CSFMLWindow* window, CSFMLApplication* app) : CScene(id, name, window, app) {}
	virtual ~CPureMenuScene();
};

