#include "stdafx.h"
#include "Application.h"

void CApplication::init(VideoMode o_videoMode, const String str_title)
{
	m_window.create(o_videoMode, str_title);
}

void CApplication::update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			destroy();
	}
}

void CApplication::render()
{
	if (m_window.isOpen()) {
		m_window.clear();		//clear the previous content of the window.		
		// call render() for all worlds.
		m_window.display();		//display in window all rendered elements.
	}
}

void CApplication::destroy()
{
	if (m_window.isOpen()) {
		m_window.close();
	}
}

void CApplication::resizeWindow(int n_width, int n_height, std::string str_title)
{
	m_window.create(VideoMode(n_width,n_height), str_title);
}

CApplication::CApplication()
{
	m_window.create(VideoMode(500, 500), "Generic Window");
}

CApplication::~CApplication()
{
}
