#include "stdafx.h"
#include "GameScene.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "Fsm.h"


unsigned int CGameScene::update(void * pObject)
{
	Event* pEvent = reinterpret_cast<Event*>(pObject);

	switch (pEvent->type)
	{	
	default: 
	{
		m_world.update();
	}		
		break;
	}	
	return 0;
}

void CGameScene::init()
{
	m_world.init();
}

void CGameScene::render(RenderWindow & wnd)
{
	m_world.render(wnd);
}

void CGameScene::destroy()
{
	m_world.destroy();
}

void CGameScene::onMouseReleased(int x, int y, short btn)
{

}

void CGameScene::onMouseMove(int x, int y)
{

}

CGameScene::~CGameScene()
{
	destroy();
}
