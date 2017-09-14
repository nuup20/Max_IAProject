#include "stdafx.h"
#include "Application.h"

void CApplication::init(int wndWidth, int wndHeight, const string& str_title)
{
	m_window.create(sf::VideoMode(wndWidth, wndHeight), str_title);
	m_world.init();
}

void CApplication::wndProc()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			destroy();
	}
}

void CApplication::update()
{
	m_world.update();
}

void CApplication::render()
{
	m_window.clear();			//clear the previous content of the window.		
	m_world.render(m_window);	// call render() for all worlds.
	m_window.display();			//display in window all rendered elements.	
}

void CApplication::destroy()
{
	m_world.destroy();
	m_window.close();	
}

void CApplication::resizeWindow(int n_width, int n_height, const string& str_title)
{
	init(n_width, n_height, str_title);
}

CApplication::CApplication()
{
	
}

CApplication::~CApplication()
{
	destroy();
}
