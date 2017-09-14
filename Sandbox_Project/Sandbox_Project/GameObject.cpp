#include "stdafx.h"
#include "GameObject.h"

void CGameObject::init()
{
}

void CGameObject::update()
{
}

void CGameObject::render(RenderWindow & wnd)
{
	int x = 20;
	x = 30;
}

void CGameObject::destroy()
{
}

CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
	destroy();
}
