#include "stdafx.h"
#include "SFMLApplication.h"

bool CSFMLApplication::peekEvent(Event& _event)
{
	while (m_window.pollEvent(_event)) {
		switch (_event.type) {
		case Event::Closed:
			destroy();
			return false;
			break;
		default:
			return true;
		}
	}
	return true;
}

void CSFMLApplication::init()
{
	m_world.init();
}

void CSFMLApplication::update()
{
	m_world.update();
}

void CSFMLApplication::render(RenderWindow& wnd)
{
	m_window.clear();
	m_world.render(wnd);
	m_window.display();
}

int CSFMLApplication::run()
{
	setWindow(800, 600, "Test Window");
	m_window.create(sf::VideoMode(m_wndWidth,m_wndHeight),m_wndTitle);
	sf::Event event;

	init();	
	
	while (peekEvent(event)) {
		update();
		render(m_window);
	}		
	
	destroy();
	return 0;
}

void CSFMLApplication::destroy()
{
	m_world.destroy();
	m_window.close();
}

void CSFMLApplication::setWindow(int width, int height, string title)
{
	m_wndWidth = width;
	m_wndHeight = height;
	m_wndTitle = title;
}

CSFMLApplication::CSFMLApplication()
{
}

CSFMLApplication::~CSFMLApplication()
{
	destroy();
}
