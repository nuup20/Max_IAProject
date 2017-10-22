#include "stdafx.h"
#include "OptionsScene.h"
#include "Fsm.h"

void COptionsScene::buttonFunc(unsigned int index)
{
	switch (index) {
	case BUTTONS_MENU::MENU:
		this->m_pFSM->SetState(SCENE_STATES::kMenu);
		break;	
	case BUTTONS_MENU::UNDEFINED:break;
	default:
		break;
	}
}

void COptionsScene::init()
{	
	m_title.setFont(m_font);
	m_title.setCharacterSize(64);
	m_title.setFillColor(Color::White);
	m_title.setPosition(400, 120);
	m_title.setString("Options");

	// Menu Button
	CInteractiveButton* _newBtn = new CInteractiveButton();
	_newBtn->m_name = "Back_Button";
	_newBtn->setPosition(400, 260);
	_newBtn->setLabel("Back");
	m_buttonList.push_back(_newBtn);
}

unsigned int COptionsScene::update(void * pObject)
{
	Event* pEvent = reinterpret_cast<Event*>(pObject);

	switch (pEvent->type)
	{
	case Event::MouseButtonReleased:
	{
		sf::Vector2i mousePos = Mouse::getPosition(*m_rendWindow);
		onMouseReleased(mousePos.x, mousePos.y, 0);
		pEvent->type = Event::Count;
	}
	break;
	case Event::MouseMoved:
	{
		sf::Vector2i mousePos = Mouse::getPosition(*m_rendWindow);
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

void COptionsScene::render(RenderWindow & wnd)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(wnd);
	wnd.draw(m_title);
}

void COptionsScene::destroy()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->destroy();
	m_buttonList.clear();	
}

void COptionsScene::onMouseReleased(int x, int y, short btn)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		if (m_buttonList[i]->isPressedByPosition(x, y)) {
			buttonFunc(BUTTONS_MENU::MENU);
			return;
		}
}

void COptionsScene::onMouseMove(int x, int y)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->isHoverbyPosition(x, y);
}

COptionsScene::~COptionsScene()
{
	destroy();
}
