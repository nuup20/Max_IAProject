#pragma once
#include "Application.h"
#include "SFMLWindow.h"
#include "Scene.h"
#include "MenuGM.h"
#include "GameScene.h"
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::Event;
using sf::Mouse;
using std::string;

class CSFMLApplication : public CApplication
{
private:	

	CSFMLWindow			m_appWindow;
	vector<CScene*>		m_sceneList;
	CScene*				m_activeScene;	

	bool	peekEvent(Event& _event);

public:
	void	init();
	void	update();
	void	render();
	int		run();
	void	destroy();

	bool	setActiveScene(unsigned int index);

	CSFMLApplication();
	~CSFMLApplication();
};

