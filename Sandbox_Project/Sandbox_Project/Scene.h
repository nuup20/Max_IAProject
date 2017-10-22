#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "State.h"

using std::vector;
using std::string;
using sf::RenderWindow;
using sf::Event;
using sf::Mouse;

namespace BUTTONS_MENU {
	enum b {
		GAME,
		OPTIONS,
		MENU,
		UNDEFINED
	};
}

class CScene : public CState
{
protected:
	//CSFMLApplication*	myApp;
	string				m_name;
	RenderWindow*		m_rendWindow;
public:

	void		onEnter();	
	virtual unsigned int update(void* pObject) override;
	void		onExit();

	virtual void init();
	virtual void render(RenderWindow& wnd);
	virtual void destroy();

	virtual void setName(string newName);
	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	CScene(unsigned int id, const std::string& name, RenderWindow* window) : CState(id), m_name(name), m_rendWindow(window) {}
	virtual ~CScene() {};
};

