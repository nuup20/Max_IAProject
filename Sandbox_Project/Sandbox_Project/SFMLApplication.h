#pragma once
#include "Application.h"
#include "SFMLWindow.h"
#include "Fsm.h"
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Event;
using sf::Mouse;
using std::string;

class CSFMLApplication : public CApplication
{
private:	

	CSFMLWindow			m_appWindow;
	CFsm				m_screenFSM;
	

	bool	peekEvent(Event& _event);

public:
	void	init();
	void	update();
	void	render();
	int		run();
	void	destroy();	

	CSFMLApplication();
	~CSFMLApplication();
};

