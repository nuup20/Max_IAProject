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

class CScene : public CState
{
protected:
	//CSFMLApplication*	myApp;
	string				m_name;
	RenderWindow*		m_rendWindow;
public:

	virtual void		onEnter();	
	virtual unsigned int update(void* pObject) override;
	virtual void		onExit();

	virtual void init();
	virtual void render(RenderWindow& wnd);
	virtual void destroy();

	virtual void setSceneName(string newName);
	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	CScene(unsigned int id, const std::string& name, RenderWindow* window) : CState(id), m_name(name), m_rendWindow(window) {}
	virtual ~CScene() {};
};

