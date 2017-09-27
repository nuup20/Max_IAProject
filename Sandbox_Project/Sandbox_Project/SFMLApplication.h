#pragma once
#include "Application.h"
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Event;
using std::string;

class CSFMLApplication : public CApplication
{
private:

	RenderWindow	m_window;

	int		m_wndWidth;
	int		m_wndHeight;
	string	m_wndTitle;

	bool	peekEvent(Event& _event);

public:
	void	init();
	void	update();
	void	render(RenderWindow& wnd);
	int		run();
	void	destroy();

	void	setWindow(int width, int height, string title);

	CSFMLApplication();
	~CSFMLApplication();
};

