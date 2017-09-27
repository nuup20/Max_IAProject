#include "stdafx.h"
#include "Application.h"

void CApplication::init()
{
	m_world.init();
}

void CApplication::update()
{
	m_world.update();
}

void CApplication::render()
{	
	m_world.render();	// call render() for all worlds.	
}

void CApplication::destroy()
{
	m_world.destroy();
}

int CApplication::run()
{
	return 0;
}

CApplication::CApplication()
{
	
}

CApplication::~CApplication()
{
	destroy();
}
