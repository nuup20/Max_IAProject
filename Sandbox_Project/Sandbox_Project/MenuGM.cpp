#include "stdafx.h"
#include "MenuGM.h"
#include "Fsm.h"

using sf::Event;
using sf::Mouse;

void CMenuGM::buttonFunc(unsigned int id)
{
	switch (id) {
	case BUTTONS_MENU::KSceneSelectionScn:
		this->m_pFSM->SetState(SCENE_STATES::kSceneSelection);
		break;
	case BUTTONS_MENU::kOptionsScn:
		this->m_pFSM->SetState(SCENE_STATES::kOptions);
		break;
	case BUTTONS_MENU::kUndefined:break;
	default:
		break;
	}
}

void CMenuGM::init()
{	
	// Play Button
	CInteractiveButton* _newBtn = new CInteractiveButton(BUTTONS_MENU::KSceneSelectionScn);
	_newBtn->m_name = "Play_Button";
	_newBtn->setPosition(400, 400);	
	_newBtn->setLabel("Start");	
	m_buttonList.push_back(_newBtn);

	// Option Button
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kOptionsScn);
	_newBtn->m_name = "Option_Button";
	_newBtn->setPosition(400, 500);	
	_newBtn->setLabel("Options");	
	m_buttonList.push_back(_newBtn);

	// Main Title Sprite
	m_titleTexture.loadFromFile("gameResources/sprites/spr_MainTitle_01.png");
	m_titleSprite.setTexture(m_titleTexture);
	m_titleSprite.setPosition(250, 50);
	
}

void CMenuGM::render(RenderWindow & wnd)
{
	wnd.draw(m_titleSprite);
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		m_buttonList[i]->render(wnd);	

}

