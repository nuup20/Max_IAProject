#include "stdafx.h"
#include "PursuitScreen.h"
#include "SFMLWindow.h"

void CPursuitScreen::buttonFunc(int id)
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

void CPursuitScreen::init()
{
	m_world.init();
	m_sfmlWnd->setClearColor(60, 122, 67);

	CRendObject* _newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Street_01";
	_newR->setPosition(510, 100);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_street_01.png");
	m_world.addGameObject(_newR);

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Street_02";
	_newR->setPosition(100, 360);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_street_02.png");
	m_world.addGameObject(_newR);

	// GO : THIEF
	CBoid* _newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Thief";
	_newGO->setPosition(10, 100);
	_newGO->setDirection(1.0f, 0.0f);
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->scaleSprite(0.5f);
	_newGO->setLayer(1);
	_newGO->setVelocity(100.0f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_audi_01.png");
	m_world.addGameObject(_newGO);
	CBoid* objective = _newGO;

	_newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Police";
	_newGO->setPosition(100, 700);
	_newGO->setDirection(0.0f, -1.0f);	
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->scaleSprite(0.5f);
	_newGO->setLayer(1);
	_newGO->setVelocity(190.0f);
	_newGO->setObjective(objective);
	_newGO->setActiveState(BOIDSTATE::kPursuit);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_police_01.png");
	m_world.addGameObject(_newGO);

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

CPursuitScreen::~CPursuitScreen()
{
}
