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
		default:{	
			
			}
			return true;
		}
	}
	m_screenFSM.UpdateState(reinterpret_cast<void*>(&_event));
	return true;
}

void CSFMLApplication::init()
{		
	m_appWindow.initWindow(1024, 720, "SandBox");

	m_screenFSM.AddState(reinterpret_cast<CState*>(new CMenuGM("Menu Scene", &m_appWindow.m_window)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new COptionsScene("Options Scene", &m_appWindow.m_window)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new CSceneSelection("Select Game Scene", &m_appWindow.m_window)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new CSeekScreen("Game Scene", &m_appWindow.m_window)));
	m_screenFSM.SetState(SCENE_STATES::kMenu);	

}

void CSFMLApplication::update()
{
	m_appWindow.update();
}

void CSFMLApplication::render()
{
	m_appWindow.clear(sf::Color(49,143,194,255));
	if (m_screenFSM.m_aciveState)
	{
		CScene* pScene = reinterpret_cast<CScene*>(m_screenFSM.m_aciveState);
		pScene->render(m_appWindow.m_window);
	}
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
}

CSFMLApplication::CSFMLApplication()
{
}

CSFMLApplication::~CSFMLApplication()
{
	destroy();
}
