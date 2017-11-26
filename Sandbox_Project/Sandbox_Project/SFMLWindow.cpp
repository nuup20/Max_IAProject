#include "stdafx.h"
#include "SFMLWindow.h"


void CSFMLWindow::init()
{
	
}

void CSFMLWindow::update()
{
	m_wndTime.update();
}

void CSFMLWindow::render()
{
	m_window.display();
}

void CSFMLWindow::clear()
{
	m_window.clear(sf::Color(m_clearColor.x,m_clearColor.y,m_clearColor.z,255));
}

void CSFMLWindow::destroy()
{
	m_wndTime.destroy();
	m_window.close();	
}

void CSFMLWindow::initWindow(short _w, short _h, string _title)
{
	this->m_width = _w;
	this->m_height = _h;
	this->m_title = _title;
	m_window.create(VideoMode(_w, _h), _title, sf::Style::Fullscreen);
	m_wndTime.init();
}

void CSFMLWindow::setClearColor(int r, int g, int b)
{
	m_clearColor.x = (float)r;
	m_clearColor.y = (float)g;
	m_clearColor.z = (float)b;
}

RenderWindow * CSFMLWindow::getRenderWndPtr()
{
	return &m_window;
}

CVector3 CSFMLWindow::getRenderWndSize()
{
	sf::Vector2u w = m_window.getSize();
	return CVector3((float)w.x,(float)w.y);
}

bool CSFMLWindow::pollEvent(Event& _event)
{
	return m_window.pollEvent(_event);
}

float CSFMLWindow::getFrameTime()
{
	return m_wndTime.getFrameTime();
}

CSFMLWindow::~CSFMLWindow()
{
}
