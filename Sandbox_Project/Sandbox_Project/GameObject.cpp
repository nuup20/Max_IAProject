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
	
}

void CGameObject::destroy()
{
}

void CGameObject::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void CGameObject::setName(string name)
{
	m_name = name;
}

CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
	destroy();
}
