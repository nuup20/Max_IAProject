#include "stdafx.h"
#include "GameScene.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "Fsm.h"
#include "SFMLWindow.h"

#define ICO_HOFFSET 30

unsigned int CGameScene::update(void * pObject)
{
	m_time.update();
	Event* pEvent = reinterpret_cast<Event*>(pObject);

	switch (pEvent->type)
	{	
	case Event::MouseButtonReleased:
	{
		sf::Vector2i mousePos = Mouse::getPosition(*m_sfmlWnd->getRenderWndPtr());
		onMouseReleased(mousePos.x, mousePos.y, 0);
		pEvent->type = Event::Count;
	}
	break;
	case Event::MouseMoved:
	{
		sf::Vector2i mousePos = Mouse::getPosition(*m_sfmlWnd->getRenderWndPtr());
		onMouseMove(mousePos.x, mousePos.y);
	}
	break;
	default:
		for (unsigned int i = 0; i < m_buttonList.size(); ++i)
			m_buttonList[i]->update();
		break;
	}

	if (!m_isPaused)
	{
		m_world.update();
	}	
	return 0;
}

void CGameScene::buttonFunc(int id)
{
}

void CGameScene::setButtonPositions()
{
	if (m_buttonList.size() > 0)
	{
		CVector3 size = m_sfmlWnd->getRenderWndSize();
		CVector3 sprSize = m_buttonList[0]->getButtonSpriteSize();
		int maxCol = (size.x / (sprSize.x + ICO_HOFFSET)) - 1;
		
		for (int i = 0; i < m_buttonList.size(); ++i) {		

			m_buttonList[i]->setPosition(ICO_HOFFSET + ((ICO_HOFFSET + sprSize.x) * i), size.y - 30 - sprSize.y);
			m_buttonList[i]->updateButtonParams();		

			m_buttonList[i]->setNormalColor(180, 180, 180, 255);
			m_buttonList[i]->setHoverColor(255, 255, 255, 255);
		}
	}
	return;
}

void CGameScene::onEnter()
{
	init();	
}

void CGameScene::onExit()
{	
	destroy();
}

void CGameScene::init()
{
	m_world.init();	
	m_time.init();
}

void CGameScene::render()
{
	m_world.render(*m_sfmlWnd->getRenderWndPtr());

	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(*m_sfmlWnd->getRenderWndPtr());
}

void CGameScene::destroy()
{
	m_time.destroy();
	m_world.destroy();
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		delete m_buttonList[i];
	m_buttonList.clear();
}

void CGameScene::onMouseReleased(int x, int y, short btn)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		if (m_buttonList[i]->isPressedByPosition(x, y)) {
			buttonFunc(m_buttonList[i]->getID());
			return;
		}
}

void CGameScene::onMouseMove(int x, int y)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->isHoverbyPosition(x, y);
}

void CGameScene::pauseSystem()
{
	m_isPaused = !m_isPaused;
}

CGameScene::~CGameScene()
{
	destroy();
}
