#include "stdafx.h"
#include "MenuGM.h"
#include "Fsm.h"
#include "SFMLWindow.h"
#include "SFMLApplication.h"

using sf::Event;
using sf::Mouse;

void CMenuGM::buttonFunc(unsigned int id)
{
	switch (id) {
	case BUTTONS_MENU::kToGame:
		this->m_pFSM->SetState(SCENE_STATES::kGame);
		break;
	case BUTTONS_MENU::kToOptions:
		this->m_pFSM->SetState(SCENE_STATES::kOptions);
		break;
	case BUTTONS_MENU::kToExit:
		destroy();
		this->m_app->destroy();
	break;
	case BUTTONS_MENU::kUndefined:break;
	default:
		break;
	}
}

void CMenuGM::init()
{	
	m_sfmlWnd->setClearColor(93, 178, 196);

	// Play Button
	CInteractiveButton* _newBtn = new CInteractiveButton(BUTTONS_MENU::kToGame);
	_newBtn->m_name = "Play_Button";
	_newBtn->setPosition(400, 400);	
	_newBtn->setLabel("Start");	
	m_buttonList.push_back(_newBtn);

	// Option Button
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kToOptions);
	_newBtn->m_name = "Option_Button";
	_newBtn->setPosition(400, 500);	
	_newBtn->setLabel("Options");	
	m_buttonList.push_back(_newBtn);

	_newBtn = new CInteractiveButton(BUTTONS_MENU::kToExit);
	_newBtn->m_name = "Exit_Button";
	_newBtn->setPosition(400, 600);
	_newBtn->setLabel("Exit");
	m_buttonList.push_back(_newBtn);

	// Main Title Sprite
	m_titleTexture.loadFromFile("gameResources/sprites/spr_MainTitle_01.png");
	m_titleSprite.setTexture(m_titleTexture);
	m_titleSprite.setPosition(250, 50);
	
}

void CMenuGM::render()
{
	m_sfmlWnd->getRenderWndPtr()->draw(m_titleSprite);
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(*m_sfmlWnd->getRenderWndPtr());

}

