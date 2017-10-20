#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
//#include "SFMLApplication.h"

using std::vector;
using std::string;
using sf::RenderWindow;

class CScene
{
protected:

	//CSFMLApplication*	myApp;
	string				m_name;
	unsigned int		m_id;	

public:

	virtual void init();
	virtual void update();
	virtual void render(RenderWindow& wnd);
	virtual void destroy();

	virtual void setName(string newName);
	virtual void onMouseClick(int x, int y, short btn);
	virtual void onMouseMove(int x, int y);

	//virtual void setMyApp(CSFMLApplication *_myApp);

	CScene();	
	virtual ~CScene();
};

