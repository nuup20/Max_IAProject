#pragma once
#include "Application.h"
#include "SFMLWindow.h"
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Event;
using std::string;

class CSFMLApplication : public CApplication
{
private:

	vector<CSFMLWindow*>		m_windowList;
	CSFMLWindow					*m_activeWindow;

	bool	peekEvent(Event& _event);

public:
	void	init();
	void	update();
	void	render();
	int		run();
	void	destroy();

	void	createWindow(short _width, short _height, string _title);
	bool	destroyWindow(unsigned int index);
	bool	setActiveWindow(unsigned int index);

	CSFMLApplication();
	~CSFMLApplication();
};

