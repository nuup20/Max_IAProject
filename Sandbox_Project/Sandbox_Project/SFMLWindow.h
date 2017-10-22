#pragma once
#include "WindowApp.h"
#include <SFML/Graphics.hpp>
#include <string>

using std::string;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Color;

class CSFMLWindow : public CWindowApp
{	
public:
	RenderWindow m_window;

	short	m_width;
	short	m_height;
	string	m_title;

	void init();
	void update();
	void render();
	void clear(const Color bckColor);
	void destroy();

	void initWindow(short _h, short _w, string title);

	CSFMLWindow();
	~CSFMLWindow();
};

