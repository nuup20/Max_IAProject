#include "stdafx.h"
#include "PathScreen.h"

void CPathScreen::buttonFunc(int id)
{
	switch (id) {
	case GAMEBUTTON::kPause:
		this->pauseSystem();
		break;
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

void CPathScreen::init()
{
	m_time.init();
	m_world.init();
	this->m_isPaused = false;

	// POLICE CAR
	CBoid* _newGO = new CBoid(this);
	_newGO->m_name = "Race Car";
	_newGO->setPosition(833, 77);
	_newGO->setDirection(-1.0f, 0.0f);
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->scaleSprite(0.35f);
	_newGO->setLayer(1);
	_newGO->setVelocity(100.f);
	_newGO->setMass(2.0f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_car_01.png");
	m_world.addGameObject(_newGO);

	CRendObject*  _newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(724, 67);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(200, 73);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(100, 153);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(96, 471);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(170, 546);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(263, 511);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(413, 318);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(566, 329);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(719, 606);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(891, 623);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(940, 189);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(882, 98);
	_newR->scale(0.50f);
	m_world.addGameObject(_newR);
	_newGO->addPathNode(_newR);		// --> Add node to police GO

	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Node";
	_newR->setPosition(512, 362);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_grandPrix.png");
	_newR->setLayer(-1);
	m_world.addGameObject(_newR);	

	//BUTTON : PAUSE
	CInteractiveButton * _newBut = new CInteractiveButton(GAMEBUTTON::kPause);
	_newBut->setName("Pause");
	_newBut->setTextureDirectory("gameResources/icons/spr_pause_01.png");
	m_buttonList.push_back(_newBut);

	//BUTTON : RESET
	_newBut = new CInteractiveButton(GAMEBUTTON::kReset);
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

CPathScreen::~CPathScreen()
{
}
