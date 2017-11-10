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

void CGameObject::setLayer(int layer) // Describe el número de capa para renderizar
{
	m_layer = layer;
}

void CGameObject::setObjectGroup(unsigned int group)
{
	m_group = group;
}


CGameObject::~CGameObject()
{
	destroy();
}
