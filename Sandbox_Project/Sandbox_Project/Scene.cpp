#include "stdafx.h"
#include "Scene.h"



void CScene::onEnter()
{
	init();
}

unsigned int CScene::update(void * pObject)
{
	m_time.update();
	return 0;
}

void CScene::onExit()
{
	destroy();
}

void CScene::init()
{
	m_time.init();
}

void CScene::render()
{

}

void CScene::destroy()
{
	m_time.destroy();
}

void CScene::setSceneName(string newName)
{
	this->m_name = newName;
}

void CScene::onMouseReleased(int x, int y, short btn)
{

}

void CScene::onMouseMove(int x, int y)
{

}

