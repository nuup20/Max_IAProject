#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class CApplication
{
public:

	RenderWindow m_window;	

	void	init(VideoMode o_videoMode, const String str_title);
	void	update();
	void	render();
	void	destroy();

	void	resizeWindow(int n_width, int n_height, std::string str_title);

	CApplication();	
	~CApplication();
};

