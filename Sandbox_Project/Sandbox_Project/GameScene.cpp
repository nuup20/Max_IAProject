#include "stdafx.h"
#include "GameScene.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "Fsm.h"
#include "SFMLWindow.h"

#include "Flag.h"
#include "Base.h"
#include "Soldier.h"
#include "Obstacle.h"

#define ICO_HOFFSET 30
#define TILE_SIZE   96
#define BCK_OFFSET	1

unsigned int CGameScene::update(void * pObject)
{
	m_time.update();
	Event* pEvent = reinterpret_cast<Event*>(pObject);

	switch (pEvent->type)
	{	
	case Event::MouseButtonReleased:
	{
		sf::Vector2i mousePos = Mouse::getPosition(*m_sfmlWnd->getRenderWndPtr());
		onMouseReleased(mousePos.x, mousePos.y, 0);
		pEvent->type = Event::Count;
	}
	break;
	case Event::MouseMoved:
	{
		sf::Vector2i mousePos = Mouse::getPosition(*m_sfmlWnd->getRenderWndPtr());
		onMouseMove(mousePos.x, mousePos.y);
	}
	break;
	default:
		vector<CInteractiveButton*> buttonList = m_world.getObjs<CInteractiveButton>();
		for (unsigned int i = 0; i < buttonList.size(); ++i)
			buttonList[i]->update();
		break;
	}

	if (!m_isPaused)
	{
		m_world.update();
	}	
	return 0;
}

void CGameScene::buttonFunc(int id)
{
}

void CGameScene::setButtonPositions()
{
	vector<CInteractiveButton*> buttonList = m_world.getObjs<CInteractiveButton>();
	if (buttonList.size() > 0)
	{
		CVector3 size = m_sfmlWnd->getRenderWndSize();
		CVector3 sprSize = buttonList[0]->getButtonSpriteSize();
		int maxCol = (size.x / (sprSize.x + ICO_HOFFSET)) - 1;
		
		for (int i = 0; i < buttonList.size(); ++i) {

			buttonList[i]->setPosition(ICO_HOFFSET + ((ICO_HOFFSET + sprSize.x) * i), size.y - 30 - sprSize.y);
			buttonList[i]->updateButtonParams();

			buttonList[i]->setNormalColor(180, 180, 180, 255);
			buttonList[i]->setHoverColor(255, 255, 255, 255);
		}
	}
	return;
}

void CGameScene::onEnter()
{
	init();	
}

void CGameScene::onExit()
{	
	destroy();
}

void CGameScene::init()
{
	m_world.init();	
	m_time.init();

	// Crea todos los tiles del background
	static const int maxColumns = (int)( 1920 / TILE_SIZE) + BCK_OFFSET;
	static const int maxRows = (int)(1080 / TILE_SIZE) + BCK_OFFSET;
	static const int tileOffset = (int)(TILE_SIZE * 0.5);

	for (unsigned int row = 0; row < maxRows; ++row)
	{
		for (unsigned int col = 0; col < maxColumns; ++col)
		{
			CRendObject* _newTile = new CRendObject();

			if (0 == row) {
				if (0 == col)
				{
					_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_SupIzq_01.png");					
				}
				else if (maxColumns - 2 == col)
				{
					_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_SupDer_01.png");
				}
				else {
					_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sandTop_01.png");
				}				
			}
			else if (maxRows - 2 == row)
			{
				if (0 == col)
				{
					_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_InfIzq_01.png");
				}
				else if (maxColumns - 2  == col)
				{
					_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_InfDer_01.png");
				} 
				else
				{
					_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_Botton_01.png");
				}				
			}
			else if (0 == col)
			{
				_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_Left_01.png");
			}
			else if (maxColumns - 2 == col)
			{
				_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_Right_01.png");
			}
			else
			{
				_newTile->setSpriteDirectory("gameResources/sprites/tiles/spr_sand_01.png");
			}
			_newTile->setColor(255.f, 255.f, 255.f, 255.f);
			_newTile->setPosition((TILE_SIZE * col) + tileOffset, (TILE_SIZE * row) + tileOffset);
			_newTile->setLayer(-1);
			m_world.addGameObject(_newTile);
		}
	}

	//OBSTACLES
	CObstacle* obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_150_obs.png");
	obs->setRadius(150.f);
	obs->setPosition(960, 540);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(160, 75);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(1760, 75);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(160, 1005);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(1760, 1005);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(1310, 540);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(610, 540);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(515, 262);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(515, 818);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(1405, 262);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(1405, 818);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(960, 180);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(960, 900);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(770, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(770, 735);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(1150, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(75.f);
	obs->setPosition(1150, 735);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(1665, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(1665, 735);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(255, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(100.f);
	obs->setPosition(255, 735);
	m_world.addGameObject(obs);

	CBase* _newBase = new CBase(TEAM::kRed);
	_newBase->setPosition(100, 540);
	m_world.addGameObject(_newBase);

	_newBase = new CBase(TEAM::kGreen);
	_newBase->setPosition(1820, 540);
	m_world.addGameObject(_newBase);

	CFlag* _newFlag = new CFlag(TEAM::kRed);	
	_newFlag->setPosition(100, 540);	
	m_world.addGameObject(_newFlag);

	_newFlag = new CFlag(TEAM::kGreen);	
	_newFlag->setPosition(1820, 540);	
	m_world.addGameObject(_newFlag);

	CSoldier* _newBoid = new CSoldier(this, TEAM::kRed);
	_newBoid->m_name = "Red Boid";
	_newBoid->setPosition(120, 540);
	_newBoid->setVelocity(100.f);	
	m_world.addGameObject(_newBoid);

	_newBoid = new CSoldier(this, TEAM::kRed);
	_newBoid->m_name = "Red Boid";
	_newBoid->setPosition(770, 546);
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);
}

void CGameScene::render()
{
	m_world.render(*m_sfmlWnd->getRenderWndPtr());

	vector<CInteractiveButton*> buttonList = m_world.getObjs<CInteractiveButton>();
	for (unsigned int i = 0; i < buttonList.size(); ++i)
		buttonList[i]->render(*m_sfmlWnd->getRenderWndPtr());
}

void CGameScene::destroy()
{
	m_time.destroy();
	m_world.destroy();
}

void CGameScene::onMouseReleased(int x, int y, short btn)
{
	vector<CInteractiveButton*> buttonList = m_world.getObjs<CInteractiveButton>();
	for (unsigned int i = 0; i < buttonList.size(); ++i)
		if (buttonList[i]->isPressedByPosition(x, y)) {
			buttonFunc(buttonList[i]->getID());
			return;
		}
}

void CGameScene::onMouseMove(int x, int y)
{
	vector<CInteractiveButton*> buttonList = m_world.getObjs<CInteractiveButton>();
	for (unsigned int i = 0; i < buttonList.size(); ++i)
		buttonList[i]->isHoverbyPosition(x, y);
}

void CGameScene::pauseSystem()
{
	m_isPaused = !m_isPaused;
}

CGameScene::~CGameScene()
{
	destroy();
}
