#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "WindowTime.h"

using std::vector;
using std::string;
using sf::RenderWindow;
using sf::Event;
using sf::Mouse;

class CSFMLWindow;
class CWindowTime;
class CSFMLApplication;
class CScene : public CState
{
protected:	
	string				m_name;
	CSFMLWindow*		m_sfmlWnd;
	CSFMLApplication*	m_app;

public:
	CWindowTime			m_time;

	virtual void		onEnter();	
	virtual unsigned int update(void* pObject) override;
	virtual void		onExit();

	virtual void init();
	virtual void render();
	virtual void destroy();

	virtual void setSceneName(string newName);
	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	CScene(unsigned int id, const std::string& name, CSFMLWindow* window, CSFMLApplication* app) : CState(id), m_name(name), m_sfmlWnd(window), m_app(app) {}
	virtual ~CScene() {};
};

