#include "stdafx.h"
#include "SFMLApplication.h"

#include "Scene.h"
#include "MenuGM.h"
#include "SeekScreen.h"
#include "SceneSelection.h"
#include "ArriveScreen.h"
#include "WanderScreen.h"
#include "PursuitScreen.h"
#include "OptionsScene.h"

bool CSFMLApplication::peekEvent(Event& _event)
{
	while (m_appWindow.pollEvent(_event)) {
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
	m_appWindow.initWindow(1024, 720, "Inteligencia Artificial Project");

	m_screenFSM.AddState(reinterpret_cast<CState*>(new CMenuGM("Menu Scene", &m_appWindow)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new COptionsScene("Options Scene", &m_appWindow)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new CSceneSelection("Select Game Scene", &m_appWindow)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new CSeekScreen("Seek Screen", &m_appWindow)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new CArriveScreen("Arrive Screen", &m_appWindow)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new CWanderScreen("Wander Screen", &m_appWindow)));
	m_screenFSM.AddState(reinterpret_cast<CState*>(new CPursuitScreen("Pursuit Screen", &m_appWindow)));
	m_screenFSM.SetState(SCENE_STATES::kMenu);	

}

void CSFMLApplication::update()
{	
	m_appWindow.update();
}

void CSFMLApplication::render()
{
	m_appWindow.clear();
	if (m_screenFSM.m_aciveState)
	{
		CScene* pScene = reinterpret_cast<CScene*>(m_screenFSM.m_aciveState);
		pScene->render();
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
