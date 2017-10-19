#include "stdafx.h"
#include "SFMLApplication.h"

bool CSFMLApplication::peekEvent(Event& _event)
{
	while (m_activeWindow->m_window.pollEvent(_event)) {
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
	createWindow(800, 600, "mainWindow");
	if (m_windowList.size() > 0)
		m_activeWindow = m_windowList[0];
}

void CSFMLApplication::update()
{
	m_world.update();	
}

void CSFMLApplication::render()
{
	m_activeWindow->clear();
	m_world.render(m_activeWindow->m_window);
	m_activeWindow->render();
}

int CSFMLApplication::run()
{	
	sf::Event event;	
	
	while (peekEvent(event)) {
		update();
		render();
	}		
	
	destroy();
	return 0;
}

void CSFMLApplication::destroy()
{
	m_world.destroy();
	for(unsigned int i = 0; i < m_windowList.size(); ++i)
		m_windowList[i]->destroy();
}

void CSFMLApplication::createWindow(short _width, short _height, string _title)
{
	CSFMLWindow *newWindow = new CSFMLWindow;
	newWindow->initWindow(_height, _width, _title);
	m_windowList.push_back(newWindow);	
}

bool CSFMLApplication::destroyWindow(unsigned int index)
{
	if (index >= m_windowList.size())
		return false;
	m_windowList[index]->destroy();
	
}

bool CSFMLApplication::setActiveWindow(unsigned int index)
{
	if (m_windowList.size() < index) {
		m_activeWindow = m_windowList[index];
		return true;
	}		
	return false;
}

CSFMLApplication::CSFMLApplication()
{
}

CSFMLApplication::~CSFMLApplication()
{
	destroy();
}
