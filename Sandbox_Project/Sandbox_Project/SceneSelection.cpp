#include "stdafx.h"
#include "SceneSelection.h"
#include "Fsm.h"
#include "SFMLWindow.h"

#define ICO_SIZE	110
#define ICO_HOFFSET	40 
#define ICO_VOFFSET 40
#define ICO_MARGIN  150

void CSceneSelection::buttonFunc(unsigned int id)
{
	switch (id) {
	case BUTTONS_MENU::kMenuScn:
		this->m_pFSM->SetState(SCENE_STATES::kMenu);
		break;
	case BUTTONS_MENU::KSeekFleeScn:
		this->m_pFSM->SetState(SCENE_STATES::kSeekScene);
		break;	
	case BUTTONS_MENU::kArriveScr:
		this->m_pFSM->SetState(SCENE_STATES::kArriveScene);
		break;
	case BUTTONS_MENU::kWanderScr:
		this->m_pFSM->SetState(SCENE_STATES::kWanderScn);
		break;
	case BUTTONS_MENU::kPursuitScr:
		this->m_pFSM->SetState(SCENE_STATES::kPursuitScn);
		break;
	case BUTTONS_MENU::kPathScn:
		this->m_pFSM->SetState(SCENE_STATES::kPathScene);
		break;
	case BUTTONS_MENU::kAvoidanceScn:
		this->m_pFSM->SetState(SCENE_STATES::kAvoidance);
		break;
	case BUTTONS_MENU::kFlockScn:
		this->m_pFSM->SetState(SCENE_STATES::kFlock);
		break;
	case BUTTONS_MENU::kUndefined:break;
	default:
		break;
	}
}

void CSceneSelection::setButtonPositions()
{
	CVector3 size = m_sfmlWnd->getRenderWndSize();
	int maxCol = ( (int)size.x / (ICO_SIZE + ICO_HOFFSET) ) - 1;

	int row = 0;
	int col = 0;	
	for (unsigned int i = 0; i < m_buttonList.size(); ++i) {
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
	m_sfmlWnd->setClearColor(93, 178, 196);

	//Title
	m_title.setFont(m_font);
	m_title.setCharacterSize(64);
	m_title.setFillColor(Color::White);
	this->setTitlePostion(250, 40);
	this->setTitle("Scene Selection");

	//BUTTON : SEEK / FLEE SCREEN
	CInteractiveButton* _newBtn = new CInteractiveButton(BUTTONS_MENU::KSeekFleeScn);
	_newBtn->m_name = "Seek Flee Screen";	
	_newBtn->setLabel("Seek");		
	_newBtn->setTextureDirectory("gameResources/icons/spr_seekflee_01.png");
	m_buttonList.push_back(_newBtn);

	//BUTTON : ARRIVE SCREEN
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kArriveScr);
	_newBtn->m_name = "Arrive Screen";
	_newBtn->setLabel("Arrive");
	_newBtn->setTextureDirectory("gameResources/icons/spr_arrive_01.png");
	m_buttonList.push_back(_newBtn);

	//BUTTON : WANDER
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kWanderScr);
	_newBtn->m_name = "Wander Screen";
	_newBtn->setLabel("Arrive");
	_newBtn->setTextureDirectory("gameResources/icons/spr_wander_01.png");
	m_buttonList.push_back(_newBtn);

	//BUTTON : PURSUIT
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kPursuitScr);
	_newBtn->m_name = "Pursuit Screen";
	_newBtn->setLabel("Arrive");
	_newBtn->setTextureDirectory("gameResources/icons/spr_pursuit_01.png");
	m_buttonList.push_back(_newBtn);

	//BUTTON : FOLLOW PATH
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kPathScn);
	_newBtn->m_name = "Path Screen";
	_newBtn->setLabel("Path");
	_newBtn->setTextureDirectory("gameResources/icons/spr_path_01.png");
	m_buttonList.push_back(_newBtn);

	//BUTTON : AVOIDANCE
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kAvoidanceScn);
	_newBtn->m_name = "Avoidance";
	_newBtn->setLabel("Avoidance");
	_newBtn->setTextureDirectory("gameResources/icons/spr_avoidance_01.png");
	m_buttonList.push_back(_newBtn);

	//BUTTON : FLOCKING
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kFlockScn);
	_newBtn->m_name = "Flock";
	_newBtn->setLabel("Flock");
	_newBtn->setTextureDirectory("gameResources/icons/spr_avoidance_01.png");
	m_buttonList.push_back(_newBtn);

	//BUTTON : BACK TO MENU
	_newBtn = new CInteractiveButton(BUTTONS_MENU::kMenuScn);
	_newBtn->m_name = "Back";
	_newBtn->setLabel("Back");
	_newBtn->setTextureDirectory("gameResources/icons/spr_back_01.png");
	m_buttonList.push_back(_newBtn);

	//Position Buttons in Screen
	setButtonPositions();

}
