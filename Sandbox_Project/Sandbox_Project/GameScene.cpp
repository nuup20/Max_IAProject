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

	m_redScoreText.setString(to_string(m_redScore));
	m_greenScoreText.setString(to_string(m_greenScore));
	m_redMarkText.setString(to_string(m_redMarks));
	m_greenMarkText.setString(to_string(m_greenMarks));

	return 0;
}

void CGameScene::buttonFunc(int id)
{
	if (id == GAMEBUTTON::KDebug)
	{
		vector<CBoid*> boidList = m_world.getObjs<CBoid>();
		for (auto boid : boidList)
		{
			boid->setDebug();
		}
	}
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

	m_redMarks = m_greenMarks = m_greenScore = m_redScore = 0;

	m_scoreFont.loadFromFile("fonts/Keep_Singing.ttf");
	m_redScoreText.setFont(m_scoreFont);
	m_greenScoreText.setFont(m_scoreFont);
	m_redMarkText.setFont(m_scoreFont);
	m_greenMarkText.setFont(m_scoreFont);

	m_redScoreText.setCharacterSize(80);
	m_greenScoreText.setCharacterSize(80);
	m_redMarkText.setCharacterSize(60);
	m_greenMarkText.setCharacterSize(60);

	m_redScoreText.setPosition(700, 980);
	m_greenScoreText.setPosition(1170, 980);
	m_redMarkText.setPosition(340, 990);
	m_greenMarkText.setPosition(1510, 990);	

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
	obs->setRadius(75.f);
	obs->setPosition(960, 540);
	m_world.addGameObject(obs);	

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(1310, 540);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(610, 540);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(515, 262);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(515, 818);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(1405, 262);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(1405, 818);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(960, 180);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(960, 900);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(37.f);
	obs->setPosition(770, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(37.f);
	obs->setPosition(770, 735);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(37.f);
	obs->setPosition(1150, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_75_obs.png");
	obs->setRadius(37.f);
	obs->setPosition(1150, 735);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(1665, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(1665, 735);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(255, 335);
	m_world.addGameObject(obs);

	obs = new CObstacle();
	obs->setSpriteDirectory("gameResources/sprites/spr_100_obs.png");
	obs->setRadius(50.f);
	obs->setPosition(255, 735);
	m_world.addGameObject(obs);

	//INVISIBLE OBSTACLES
	for (int i = 0; i < 13; ++i)
	{
		obs = new CObstacle();		
		obs->setRadius(150.f);
		obs->setPosition(i * 150, 0);
		obs->m_isVisible = false;
		m_world.addGameObject(obs);
	}

	for (int i = 0; i < 14; ++i)
	{
		obs = new CObstacle();
		obs->setRadius(150.f);
		obs->setPosition(i * 150, 1080);
		obs->m_isVisible = false;
		m_world.addGameObject(obs);
	}

	for (int i = 0; i < 7; ++i)
	{
		obs = new CObstacle();
		obs->setRadius(150.f);
		obs->setPosition(0, i * 150);
		obs->m_isVisible = false;
		m_world.addGameObject(obs);
	}

	for (int i = 0; i < 7; ++i)
	{
		obs = new CObstacle();
		obs->setRadius(150.f);
		obs->setPosition(1920, i * 150);
		obs->m_isVisible = false;
		m_world.addGameObject(obs);
	}

	// BASE
	CBase* _newBase = new CBase(TEAM::kRed);
	_newBase->setPosition(200, 540);
	m_world.addGameObject(_newBase);

	_newBase = new CBase(TEAM::kGreen);
	_newBase->setPosition(1720, 540);
	m_world.addGameObject(_newBase);

	// FLAGS
	CFlag* _newFlag = new CFlag(TEAM::kRed);	
	_newFlag->setPosition(200, 540);	
	m_world.addGameObject(_newFlag);

	_newFlag = new CFlag(TEAM::kGreen);	
	_newFlag->setPosition(1720, 540);	
	m_world.addGameObject(_newFlag);

	// RED SOLDIERS
	CSoldier* _newBoid = new CSoldier(this, TEAM::kRed);
	_newBoid->m_name = "Red Boid";
	_newBoid->setPosition(120, 200);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);	
	m_world.addGameObject(_newBoid);
		
	_newBoid = new CSoldier(this, TEAM::kRed);
	_newBoid->m_name = "Red Boid";
	_newBoid->setPosition(260, 523);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);
	
	_newBoid = new CSoldier(this, TEAM::kRed);
	_newBoid->m_name = "Red Boid";
	_newBoid->setPosition(120, 870);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	_newBoid = new CSoldier(this, TEAM::kRed);
	_newBoid->m_name = "Red Boid";
	_newBoid->setPosition(390, 760);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	_newBoid = new CSoldier(this, TEAM::kRed);
	_newBoid->m_name = "Red Boid";
	_newBoid->setPosition(380, 300);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	// GREEN SOLDIERS
	_newBoid = new CSoldier(this, TEAM::kGreen);
	_newBoid->m_name = "Green Boid";
	_newBoid->setPosition(1662, 543);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	_newBoid = new CSoldier(this, TEAM::kGreen);
	_newBoid->m_name = "Green Boid";
	_newBoid->setPosition(1764, 202);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	_newBoid = new CSoldier(this, TEAM::kGreen);
	_newBoid->m_name = "Green Boid";
	_newBoid->setPosition(1764, 864);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	_newBoid = new CSoldier(this, TEAM::kGreen);
	_newBoid->m_name = "Green Boid";
	_newBoid->setPosition(1524, 754);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	_newBoid = new CSoldier(this, TEAM::kGreen);
	_newBoid->m_name = "Green Boid";
	_newBoid->setPosition(1525, 300);
	_newBoid->m_respawnPosition = _newBoid->m_position;
	_newBoid->setVelocity(100.f);
	m_world.addGameObject(_newBoid);

	//SCORES
	CRendObject* score = new CRendObject();
	score->m_layer = 3;
	score->setSpriteDirectory("gameResources/sprites/spr_redScore.png");
	score->setPosition(457,920);	
	m_world.addGameObject(score);

	score = new CRendObject();
	score->m_layer = 3;
	score->setSpriteDirectory("gameResources/sprites/spr_greenScore.png");
	score->setPosition(1463, 920);
	m_world.addGameObject(score);

	CInteractiveButton* debugger = new CInteractiveButton(GAMEBUTTON::KDebug);
	debugger->init();
	debugger->setTextureDirectory("gameResources/icons/spr_debug.png");
	debugger->setPosition(886, 970);
	debugger->setName("Debugger Button");
	debugger->setNormalColor(200, 200, 200, 255);
	debugger->setHoverColor(255, 255, 255, 255);
	debugger->setLayer(4);
	m_world.addGameObject(debugger);
}

void CGameScene::render()
{
	m_world.render(*m_sfmlWnd->getRenderWndPtr());

	vector<CInteractiveButton*> buttonList = m_world.getObjs<CInteractiveButton>();
	for (unsigned int i = 0; i < buttonList.size(); ++i)
		buttonList[i]->render(*m_sfmlWnd->getRenderWndPtr());

	(m_sfmlWnd->getRenderWndPtr())->draw(m_greenMarkText);
	(m_sfmlWnd->getRenderWndPtr())->draw(m_redMarkText);
	(m_sfmlWnd->getRenderWndPtr())->draw(m_greenScoreText);
	(m_sfmlWnd->getRenderWndPtr())->draw(m_redScoreText);
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

bool CGameScene::destroyObject(CGameObject * obj)
{	
	return m_world.destroyGameObject(obj);
}

void CGameScene::addNewObject(CGameObject * obj)
{
	m_world.addGameObject(obj);
}

void CGameScene::addPoint(unsigned int team, unsigned int points)
{
	if (team == TEAM::kRed)
	{
		m_redScore += points;
	}
	else
	{
		m_greenScore += points;
	}
}

void CGameScene::addDeathMan(unsigned int team)
{
	if (team == TEAM::kRed)
	{
		m_greenMarks += 1;
	}
	else
	{
		m_redMarks += 1;
	}
}

CGameScene::~CGameScene()
{
	destroy();
}
