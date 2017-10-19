#pragma once
#include "WindowApp.h"
#include <SFML/Graphics.hpp>
#include <string>

using std::string;
using sf::RenderWindow;
using sf::VideoMode;
class CSFMLWindow : public CWindowApp
{	
public:
	RenderWindow m_window;

	short	m_width;
	short	m_height;
	string	m_title;

	virtual void init();
	virtual void update();
	virtual void render();
	virtual void clear();
	virtual void destroy();

	virtual void initWindow(short _h, short _w, string title);

	CSFMLWindow();
	virtual ~CSFMLWindow();
};

