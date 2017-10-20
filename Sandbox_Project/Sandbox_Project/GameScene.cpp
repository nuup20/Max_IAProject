#include "stdafx.h"
#include "GameScene.h"

void CGameScene::init()
{
	m_world.init();
}

void CGameScene::update()
{
	m_world.update();
}

void CGameScene::render(RenderWindow & wnd)
{
	m_world.render(wnd);
}

void CGameScene::destroy()
{
	m_world.destroy();
}

void CGameScene::onMouseClick(int x, int y, short btn)
{

}

void CGameScene::onMouseMove(int x, int y)
{
}

CGameScene::CGameScene()
{
}


CGameScene::~CGameScene()
{
	destroy();
}
