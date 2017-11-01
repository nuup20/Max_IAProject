#include "stdafx.h"
#include "OptionsScene.h"
#include "Fsm.h"

void COptionsScene::buttonFunc(unsigned int id)
{
	switch (id) {
	case BUTTONS_MENU::kMenuScn:
		this->m_pFSM->SetState(SCENE_STATES::kMenu);
		break;	
	case BUTTONS_MENU::kUndefined:break;
	default:
		break;
	}
}

void COptionsScene::init()
{	
	m_title.setFont(m_font);
	m_title.setCharacterSize(64);
	m_title.setFillColor(Color::White);
	this->setTitlePostion(400, 120);
	this->setTitle("Options");

	// Menu Button
	CInteractiveButton* _newBtn = new CInteractiveButton(BUTTONS_MENU::kMenuScn);
	_newBtn->m_name = "Back_Button";
	_newBtn->setPosition(400, 260);
	_newBtn->setLabel("Back");
	m_buttonList.push_back(_newBtn);
}

COptionsScene::~COptionsScene()
{
	destroy();
}
