#include "stdafx.h"
#include "SeekScreen.h"

void CSeekScreen::init()
{
	m_world.init();

	//ISLAND
	CRendObject* _newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Island_01";
	_newR->setPosition(100, 100);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_island_01.png");	
	m_world.addGameObject(_newR);

	//CREATE SHIP
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Objective";
	_newR->setPosition(512, 360);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_crusier.png");	
	m_world.addGameObject(_newR);

	//CREATE AGENT
	CBoid* _newGO = new CBoid();
	_newGO->init();
	_newGO->m_name = "Agent";
	_newGO->setPosition(100, 500);
	_newGO->m_direction = CVector3(0.0f, -1.0f, 0.0f);
	_newGO->scaleSprite(0.8f);
	_newGO->setSpriteDirectory("gameResources/sprites/spr_plane.png");
	_newGO->setObjective(_newR);
	_newGO->setLayer(1);				// SET RENDER LAYER
	m_world.addGameObject(_newGO);

	//ISLAND
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Island_02";
	_newR->setPosition(500, 100);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_island_01.png");
	_newR->scale(0.2f);
	m_world.addGameObject(_newR);

	//ISLAND
	_newR = new CRendObject();
	_newR->init();
	_newR->m_name = "Island_03";
	_newR->setPosition(1000, 800);
	_newR->setColor(255, 255, 255, 255);
	_newR->setSpriteDirectory("gameResources/sprites/spr_island_01.png");
	m_world.addGameObject(_newR);
}
