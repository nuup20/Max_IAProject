#pragma once
#include "WindowApp.h"
#include "WindowTime.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Vector3.h"


using std::string;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Color;
using sf::Event;
using sf::Clock;
using sf::Time;

class CSFMLWindow : public CWindowApp
{	
private:
	CVector3	m_clearColor;
	short		m_width;
	short		m_height;
	string		m_title;

	// Window Time
	CWindowTime m_wndTime;

	// Window
	RenderWindow m_window;

public:
	void init();
	void update();
	void render();
	void clear();
	void destroy();

	void			initWindow(short _h, short _w, string title);
	void			setClearColor(int r, int g, int b);
	RenderWindow*	getRenderWndPtr();
	CVector3		getRenderWndSize();
	bool			pollEvent(Event& _event);
	float 			getFrameTime();


	CSFMLWindow() : m_clearColor(CVector3(255, 255, 255)) {}
	~CSFMLWindow();
};

