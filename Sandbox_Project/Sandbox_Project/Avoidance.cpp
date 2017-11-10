#include "stdafx.h"
#include "Avoidance.h"
#include "SFMLWindow.h"

#define OBSRADIUS 100.0f

void CAvoidance::buttonFunc(int id)
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

void CAvoidance::init()
{
	m_time.init();
	m_world.init();
	this->m_isPaused = false;
	m_sfmlWnd->setClearColor(0, 0, 0);

	CObstacle* _newObs = new CObstacle();
	_newObs->init();
	_newObs->m_name = "Meteor";
	_newObs->setPosition(823, 260);
	_newObs->setColor(255, 255, 255, 255);
	_newObs->setSpriteDirectory("gameResources/sprites/spr_meteor_01.png");
	_newObs->scale(0.5f);
	_newObs->setRadius(OBSRADIUS);
	m_world.addGameObject(_newObs);

	_newObs = new CObstacle();
	_newObs->init();
	_newObs->m_name = "Meteor";
	_newObs->setPosition(640, 186);
	_newObs->setColor(255, 255, 255, 255);
	_newObs->setSpriteDirectory("gameResources/sprites/spr_meteor_01.png");
	_newObs->scale(0.5f);
	_newObs->setRadius(OBSRADIUS);
	m_world.addGameObject(_newObs);

	_newObs = new CObstacle();
	_newObs->init();
	_newObs->m_name = "Meteor";
	_newObs->setPosition(558, 385);
	_newObs->setColor(255, 255, 255, 255);
	_newObs->setSpriteDirectory("gameResources/sprites/spr_meteor_01.png");
	_newObs->scale(0.5f);
	_newObs->setRadius(OBSRADIUS);
	m_world.addGameObject(_newObs);

	_newObs = new CObstacle();
	_newObs->init();
	_newObs->m_name = "Meteor";
	_newObs->setPosition(802, 470);
	_newObs->setColor(255, 255, 255, 255);
	_newObs->setSpriteDirectory("gameResources/sprites/spr_meteor_01.png");
	_newObs->scale(0.5f);
	_newObs->setRadius(OBSRADIUS);
	m_world.addGameObject(_newObs);

	_newObs = new CObstacle();
	_newObs->init();
	_newObs->m_name = "Meteor";
	_newObs->setPosition(505, 610);
	_newObs->setColor(255, 255, 255, 255);
	_newObs->setSpriteDirectory("gameResources/sprites/spr_meteor_01.png");
	_newObs->scale(0.5f);
	_newObs->setRadius(OBSRADIUS);
	m_world.addGameObject(_newObs);

	_newObs = new CObstacle();
	_newObs->init();
	_newObs->m_name = "Meteor";
	_newObs->setPosition(322, 470);
	_newObs->setColor(255, 255, 255, 255);
	_newObs->setSpriteDirectory("gameResources/sprites/spr_meteor_01.png");
	_newObs->scale(0.5f);
	_newObs->setRadius(OBSRADIUS);
	m_world.addGameObject(_newObs);

	_newObs = new CObstacle();
	_newObs->init();
	_newObs->m_name = "Meteor";
	_newObs->setPosition(337, 266);
	_newObs->setColor(255, 255, 255, 255);
	_newObs->setSpriteDirectory("gameResources/sprites/spr_meteor_01.png");
	_newObs->scale(0.5f);
	_newObs->setRadius(OBSRADIUS);
	m_world.addGameObject(_newObs);

	CRendObject* _newRend = new CRendObject();
	_newRend->init();
	_newRend->m_name = "Earth";
	_newRend->setPosition(950, 75);
	_newRend->setColor(255, 255, 255, 255);
	_newRend->setSpriteDirectory("gameResources/sprites/spr_earth_01.png");
	m_world.addGameObject(_newRend);

	CBoid* ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(35, 725);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->addNewTarget(_newRend, BOIDTARGET::kSeek);
	ship->setVelocity(60.0f);
	ship->scaleSprite(0.8f);
	m_world.addGameObject(ship);

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

CAvoidance::~CAvoidance()
{
}
