#include "stdafx.h"
#include "MenuGM.h"
#include "Fsm.h"

using sf::Event;
using sf::Mouse;

void CMenuGM::buttonFunc(unsigned int id)
{
	switch (id) {
	case BUTTONS_MENU::SCENESELECTION:
		this->m_pFSM->SetState(SCENE_STATES::kSceneSelection);
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
	this->setTitlePostion(350, 120);
	this->setTitle("SandBox");
	
	// Play Button
	CInteractiveButton* _newBtn = new CInteractiveButton(BUTTONS_MENU::SCENESELECTION);
	_newBtn->m_name = "Play_Button";
	_newBtn->setPosition(400, 260);	
	_newBtn->setLabel("Play!");	
	m_buttonList.push_back(_newBtn);

	// Option Button
	_newBtn = new CInteractiveButton(BUTTONS_MENU::OPTIONS);
	_newBtn->m_name = "Option_Button";
	_newBtn->setPosition(400, 360);	
	_newBtn->setLabel("Options");	
	m_buttonList.push_back(_newBtn);
	
}

