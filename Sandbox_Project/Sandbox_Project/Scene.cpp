#include "stdafx.h"
#include "Scene.h"


void CScene::onEnter()
{
	init();
}

unsigned int CScene::update(void * pObject)
{
	return 0;
}

void CScene::onExit()
{
	destroy();
}

void CScene::init()
{

}

void CScene::render()
{

}

void CScene::destroy()
{
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

