#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "World.h"

using sf::RenderWindow;
using std::string;

class RenderWindow;

class CApplication
{
private:
	RenderWindow m_window;
	int m_wndWidth;
	int m_wndHeight;

	CWorld	m_world;

	void	wndProc();

public:
	void	init(int wndWidth=800, int wndHeight=600, const string& str_title="TestWindow");
	void	update();
	void	render();
	void	destroy();

	void	resizeWindow(int n_width, int n_height, const string& str_title);

	CApplication();
	~CApplication();
};

