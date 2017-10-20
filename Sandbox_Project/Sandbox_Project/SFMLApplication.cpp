#include "stdafx.h"
#include "SFMLApplication.h"

bool CSFMLApplication::peekEvent(Event& _event)
{
	while (m_appWindow.m_window.pollEvent(_event)) {
		switch (_event.type) {
		case Event::Closed:
			destroy();
			return false;
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(sf::Mouse::Left))
				m_activeScene->onMouseClick(Mouse::getPosition(m_appWindow.m_window).x, Mouse::getPosition(m_appWindow.m_window).y,0);			
			break;
		default:
			return true;
		}
	}
	return true;
}

void CSFMLApplication::init()
{		
	m_appWindow.initWindow(1024, 720, "SandBox");	
	
	CMenuGM* menuScene = new CMenuGM();
	menuScene->init();
	menuScene->setName("Menu Scene");
	m_sceneList.push_back(menuScene);
	setActiveScene(0);

	CGameScene* gameScene = new CGameScene();
	gameScene->init();
	gameScene->setName("Game Scene");
	m_sceneList.push_back(gameScene);
	setActiveScene(0);

	//for (unsigned int i = 0; i < m_sceneList.size(); ++i)
		//m_sceneList[i]->setMyApp(this);

}

void CSFMLApplication::update()
{
	m_appWindow.update();
	m_activeScene->update();
}

void CSFMLApplication::render()
{
	m_appWindow.clear();	
	m_activeScene->render(m_appWindow.m_window);
	m_appWindow.render();

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
	m_appWindow.destroy();
	for (unsigned int i = 0; i < m_sceneList.size(); ++i)
		m_sceneList[i]->destroy();
}

bool CSFMLApplication::setActiveScene(unsigned int index)
{
	if (index >= m_sceneList.size())
		return false;
	if (m_activeScene != NULL)
		m_activeScene->destroy();
	m_activeScene = m_sceneList[index];
	m_activeScene->init();
	return true;
}



CSFMLApplication::CSFMLApplication()
{
}

CSFMLApplication::~CSFMLApplication()
{
	destroy();
}
