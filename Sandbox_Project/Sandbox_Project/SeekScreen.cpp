#include "stdafx.h"
#include "SeekScreen.h"
//#include "InteractiveButton.h"

void CSeekScreen::buttonFunc(int id)
{
	switch (id) {
	case GAMEBUTTON::KBack:
		this->m_pFSM->SetState(SCENE_STATES::kSceneSelection);
		break;
	case GAMEBUTTON::KSeekAgent:
		m_activeAgent->setActiveState(BOIDSTATE::kSeek);
		break;
	case GAMEBUTTON::kFleeAgent:
		m_activeAgent->setActiveState(BOIDSTATE::kFlee);
		break;
	case GAMEBUTTON::kUndefined:break;
	default:
		break;
	}
}

void CSeekScreen::init()
{
	m_world.init();

	//GO : ISLAND
	CRendObject* _newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Island_01";
	_newR->setPosition(100, 100);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_island_01.png");
	m_world.addGameObject(_newR);

	//GO : CREATE SHIP
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Objective";
	_newR->setPosition(512, 360);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_crusier.png");
	m_world.addGameObject(_newR);

	//GO : CREATE AGENT
	CBoid* _newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(100, 500);
	_newGO->setDirection(0.0f, -1.0f);
	_newGO->scaleSprite(0.8f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_plane.png");
	_newGO->setObjective(_newR);
	_newGO->setLayer(1);				// SET RENDER LAYER
	_newGO->setActiveState(BOIDSTATE::kSeek);
	m_world.addGameObject(_newGO);
	m_activeAgent = _newGO;

	//GO : ISLAND
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Island_02";
	_newR->setPosition(500, 100);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_island_01.png");
	_newR->scale(0.2f);
	m_world.addGameObject(_newR);

	//GO : ISLAND
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Island_03";
	_newR->setPosition(1000, 800);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_island_01.png");
	m_world.addGameObject(_newR);

	//BUTTON : SEEK
	CInteractiveButton* _newBut = new CInteractiveButton(GAMEBUTTON::KSeekAgent);
	_newBut->setName("Seek");
	_newBut->setTextureDirectory("gameResources/icons/spr_seek_01.png");
	m_buttonList.push_back(_newBut);

	//BUTTON : FLEE
	_newBut = new CInteractiveButton(GAMEBUTTON::kFleeAgent);
	_newBut->setName("Flee");
	_newBut->setTextureDirectory("gameResources/icons/spr_flee_01.png");
	m_buttonList.push_back(_newBut);

	//BUTTON : BACK
	_newBut = new CInteractiveButton(GAMEBUTTON::KBack);
	_newBut->setName("Back");
	_newBut->setTextureDirectory("gameResources/icons/spr_back_01.png");
	m_buttonList.push_back(_newBut);

	this->setButtonPositions();

}
