#include "stdafx.h"
#include "MenuGM.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "Fsm.h"

using sf::Event;
using sf::Mouse;

void CMenuGM::buttonFunc(unsigned int index)
{
	switch (index) {
	case BUTTONS_MENU::GAME:
		this->m_pFSM->SetState(SCENE_STATES::kGame);
		break;
	case BUTTONS_MENU::OPTIONS:
		this->m_pFSM->SetState(SCENE_STATES::kOptions);
		break;
	case BUTTONS_MENU::UNDEFINED:break;
	default:
		break;
	}
}

void CMenuGM::init()
{
	//Title	
	m_title.setFont(m_font);
	m_title.setCharacterSize(64);
	m_title.setFillColor(Color::White);
	m_title.setPosition(350, 120);
	m_title.setString("SandBox");

	// Play Button
	CInteractiveButton* _newBtn = new CInteractiveButton();
	_newBtn->m_name = "Play_Button";
	_newBtn->setPosition(400, 260);	
	_newBtn->setLabel("Play!");	
	m_buttonList.push_back(_newBtn);

	// Option Button
	_newBtn = new CInteractiveButton();
	_newBtn->m_name = "Option_Button";
	_newBtn->setPosition(400, 360);	
	_newBtn->setLabel("Options");	
	m_buttonList.push_back(_newBtn);
	
}

unsigned int CMenuGM::update(void* pObject)
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
	{
		for (unsigned int i = 0; i < m_buttonList.size(); ++i)
			m_buttonList[i]->update();
		
	}
	break;
	}
	return 0;
}

void CMenuGM::render(RenderWindow& wnd)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(wnd);
	wnd.draw(m_title);
}

void CMenuGM::destroy()
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
	{
		m_buttonList[i]->destroy();
		delete m_buttonList[i];
	}
	m_buttonList.clear();	
}

void CMenuGM::onMouseReleased(int x, int y, short btn)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		if (m_buttonList[i]->isPressedByPosition(x, y)) {
			buttonFunc(i);
			return;
		}
}

void CMenuGM::onMouseMove(int x, int y)
{
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->isHoverbyPosition(x, y);
}

CMenuGM::~CMenuGM()
{
	destroy();
}
