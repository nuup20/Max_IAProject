#include "stdafx.h"
#include "WanderScreen.h"
#include "SFMLWindow.h"

using std::vector;

void CWanderScreen::buttonFunc(int id)
{
	switch (id) {
	case GAMEBUTTON::KSeekAgent:
		for (int i = 0; i < ants.size(); ++i)
		{
			ants[i]->setWander(false);
			ants[i]->addNewTarget(m_colony, BOIDTARGET::kSeek);
		}
		break;
	case GAMEBUTTON::kWanderAgent:
		for (int i = 0; i < ants.size(); ++i)
		{
			ants[i]->setWander(true);
			ants[i]->removeTarget(BOIDTARGET::kSeek);
		}
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

void CWanderScreen::init()
{
	m_sfmlWnd->setClearColor(201, 150, 109);

	// GO : LEAVE
	CRendObject*  _newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Leave 01";
	_newR->setPosition(750, 75);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_leave_01.png");
	m_world.addGameObject(_newR);

	// GO : LEAVE
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Leave 01";
	_newR->setPosition(300, 445);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_leave_02.png");
	m_world.addGameObject(_newR);

	// GO : LEAVE
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Leave 01";
	_newR->setPosition(175, 200);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_leave_01.png");
	m_world.addGameObject(_newR);

	// GO : LEAVE
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Leave 01";
	_newR->setPosition(700, 625);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_leave_02.png");
	m_world.addGameObject(_newR);

	// GO : COLONY
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Colony";
	_newR->setPosition(500, 300);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_colony_01.png");
	m_colony = _newR;
	m_world.addGameObject(_newR);

	// GO : ANT
	CBoid* _newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(100, 500);
	_newGO->setDirection(0.0f, -1.0f);
	_newGO->setVelocity(75.0f);
	_newGO->scaleSprite(2.0f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_ant_01.png");
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->setWander(true);
	_newGO->setLayer(1);				// SET RENDER LAYER
	
	m_world.addGameObject(_newGO);
	ants.push_back(_newGO);

	_newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(300, 300);
	_newGO->setDirection(0.1f, 0.0f);
	_newGO->setVelocity(75.0f);
	_newGO->scaleSprite(2.0f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_ant_01.png");
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->setWander(true);
	_newGO->setLayer(1);				// SET RENDER LAYER
	
	m_world.addGameObject(_newGO);
	ants.push_back(_newGO);

	_newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(700, 700);
	_newGO->setDirection(-0.1f, 0.0f);
	_newGO->setVelocity(75.0f);
	_newGO->scaleSprite(2.0f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_ant_01.png");
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->setWander(true);
	_newGO->setLayer(1);				// SET RENDER LAYER
	
	m_world.addGameObject(_newGO);
	ants.push_back(_newGO);

	_newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(175, 10);
	_newGO->setDirection(0.0f, 1.0f);
	_newGO->setVelocity(75.0f);
	_newGO->scaleSprite(2.0f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_ant_01.png");
	_newGO->setSpriteColor(255, 255, 255, 255);
	_newGO->setWander(true);
	_newGO->setLayer(1);				// SET RENDER LAYER
	
	m_world.addGameObject(_newGO);
	ants.push_back(_newGO);

	//BUTTON : WANDER
	CInteractiveButton * _newBut = new CInteractiveButton(GAMEBUTTON::kWanderAgent);
	_newBut->setName("Wander");
	_newBut->setTextureDirectory("gameResources/icons/spr_wander_02.png");
	m_buttonList.push_back(_newBut);

	//BUTTON : TO COLONY
	_newBut = new CInteractiveButton(GAMEBUTTON::KSeekAgent);
	_newBut->setName("Seek");
	_newBut->setTextureDirectory("gameResources/icons/spr_tocolony_01.png");
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

void CWanderScreen::destroy()
{
	m_world.destroy();
	for (unsigned int i = 0; i < m_buttonList.size(); ++i)
		delete m_buttonList[i];
	m_buttonList.clear();
	ants.clear();
}

CWanderScreen::~CWanderScreen()
{
}
