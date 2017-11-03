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

class CSFMLWindow;
class CScene : public CState
{
protected:	
	string				m_name;
	CSFMLWindow*		m_sfmlWnd;

public:

	virtual void		onEnter();	
	virtual unsigned int update(void* pObject) override;
	virtual void		onExit();

	virtual void init();
	virtual void render();
	virtual void destroy();

	virtual void setSceneName(string newName);
	virtual void onMouseReleased(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	CScene(unsigned int id, const std::string& name, CSFMLWindow* window) : CState(id), m_name(name), m_sfmlWnd(window) {}
	virtual ~CScene() {};
};

