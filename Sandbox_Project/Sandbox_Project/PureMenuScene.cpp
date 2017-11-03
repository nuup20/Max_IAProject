#include "stdafx.h"
#include "PureMenuScene.h"
#include "SFMLWindow.h"

CPureMenuScene::~CPureMenuScene()
{
	destroy();
}

void CPureMenuScene::onEnter()
{
	init();
}

unsigned int CPureMenuScene::update(void * pObject)
{
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
	return 0;
}

void CPureMenuScene::onExit()
{
	destroy();
}

void CPureMenuScene::init()
{
}

void CPureMenuScene::render()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(*m_sfmlWnd->getRenderWndPtr());
	m_sfmlWnd->getRenderWndPtr()->draw(m_title);
}

void CPureMenuScene::destroy()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		delete m_buttonList[i];
	m_buttonList.clear();
}

void CPureMenuScene::setSceneName(string newName)
{
	this->m_name = newName;
}

void CPureMenuScene::setTitle(string newTitle)
{
	m_title.setString(newTitle);
}

void CPureMenuScene::setTitlePostion(short x, short y)
{
	m_title.setPosition(x, y);
}

void CPureMenuScene::onMouseReleased(int x, int y, short btn)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		if (m_buttonList[i]->isPressedByPosition(x, y)) {
			buttonFunc(m_buttonList[i]->getID());
			return;
		}
}

void CPureMenuScene::onMouseMove(int x, int y)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->isHoverbyPosition(x, y);
}
