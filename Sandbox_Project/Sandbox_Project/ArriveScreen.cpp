#include "stdafx.h"
#include "ArriveScreen.h"
#include "SFMLWindow.h"

void CArriveScreen::buttonFunc(int id)
{
	switch (id) {
	case GAMEBUTTON::KBack:
		this->m_pFSM->SetState(SCENE_STATES::kSceneSelection);
		break;
	case GAMEBUTTON::kReset:
		this->destroy();
		this->init();
		break;	
	case GAMEBUTTON::kUndefined:break;
	default:
		break;
	}
}

void CArriveScreen::init()
{
	m_sfmlWnd->setClearColor(64, 145, 64);

	// GO : LAND ZONE
	CRendObject*  _newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Objective";
	_newR->setPosition(750, 200);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_crusier.png");
	m_world.addGameObject(_newR);

	// GO : AIRPLANE
	CBoid* _newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(100, 500);
	_newGO->setDirection(0.0f, -1.0f);	
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_IDVPlane_01.png");
	_newGO->setObjective(_newR);
	_newGO->setLayer(1);				// SET RENDER LAYER
	_newGO->setActiveState(BOIDSTATE::kArrive);
	_newGO->setVelocity(10);
	m_world.addGameObject(_newGO);
	m_activeAgent = _newGO;

	//BUTTON : RESET
	CInteractiveButton * _newBut = new CInteractiveButton(GAMEBUTTON::kReset);
	_newBut->setName("Reset");
	_newBut->setTextureDirectory("gameResources/icons/spr_reset_01.png");
	m_buttonList.push_back(_newBut);

	//BUTTON : BACK
	_newBut = new CInteractiveButton(GAMEBUTTON::KBack);
	_newBut->setName("Back");
	_newBut->setTextureDirectory("gameResources/icons/spr_back_01.png");
	m_buttonList.push_back(_newBut);

	this->setButtonPositions();
}

CArriveScreen::~CArriveScreen()
{
}
