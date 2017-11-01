#include "stdafx.h"
#include "SceneSelection.h"
#include "Fsm.h"

#define ICO_SIZE	110
#define ICO_HOFFSET	40 
#define ICO_VOFFSET 40
#define ICO_MARGIN  150

void CSceneSelection::buttonFunc(unsigned int id)
{
	switch (id) {
	case BUTTONS_MENU::KSeekFleeScn:
		this->m_pFSM->SetState(SCENE_STATES::kSeekScene);
		break;	
	case BUTTONS_MENU::kUndefined:break;
	default:
		break;
	}
}

void CSceneSelection::setButtonPositions()
{
	sf::Vector2u size = m_rendWindow->getSize();
	int maxCol = ( size.x / (ICO_SIZE + ICO_HOFFSET) ) - 1;

	int row = 0;
	int col = 0;	
	for (int i = 0; i < m_buttonList.size(); ++i) {
		if (i > maxCol * (row + 1)) {
			++row;
			col = 0;
		}
		
		m_buttonList[i]->setPosition(ICO_HOFFSET + ((ICO_HOFFSET + ICO_SIZE) * col), ICO_VOFFSET + ICO_MARGIN + ((ICO_VOFFSET + ICO_SIZE) * row));
		m_buttonList[i]->updateButtonParams();
		++col;

		m_buttonList[i]->setNormalColor(180, 180, 180, 255);
		m_buttonList[i]->setHoverColor(255, 255, 255, 255);
	}
}

void CSceneSelection::init()
{
	//Title
	m_title.setFont(m_font);
	m_title.setCharacterSize(64);
	m_title.setFillColor(Color::White);
	this->setTitlePostion(250, 40);
	this->setTitle("Scene Selection");

	//SEEK SCREEN
	CInteractiveButton* _newBtn = new CInteractiveButton(BUTTONS_MENU::KSeekFleeScn);
	_newBtn->m_name = "Seek Flee Screen";	
	_newBtn->setLabel("Seek");		
	_newBtn->setTextureDirectory("gameResources/icons/spr_seekflee_01.png");
	m_buttonList.push_back(_newBtn);	

	//Position Buttons in Screen
	setButtonPositions();

}
