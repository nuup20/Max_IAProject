#include "stdafx.h"
#include "FlockScreen.h"
#include "SFMLWindow.h"

#define BOIDVELOCITY 30.f

void CFlockScreen::buttonFunc(int id)
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

void CFlockScreen::init()
{
	m_time.init();
	m_world.init();
	this->m_isPaused = false;
	m_sfmlWnd->setClearColor(0, 0, 0);

	CBoid* ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(241, 225);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");	
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(373, 225);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(486, 225);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(615, 225);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(768, 225);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(241, 335);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(373, 335);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(486, 335);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(615, 335);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(768, 335);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(241, 424);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(373, 424);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(486, 424);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(615, 424);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(768, 424);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(241, 533);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(373, 533);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(486, 533);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(615, 533);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	ship = new CBoid(this);
	ship->m_name = "Ship";
	ship->setPosition(768, 533);
	ship->setSpriteColor(255, 255, 255, 255);
	ship->setDirection(1.0f, 0.0f);
	ship->setSpriteDirectory("gameResources/sprites/spr_ship_01.png");
	ship->setVelocity(BOIDVELOCITY);
	ship->scaleSprite(0.5f);
	ship->setFlocking(true);
	m_world.addGameObject(ship);

	m_world.localTranslation(-300, 0);

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

CFlockScreen::~CFlockScreen()
{
}
