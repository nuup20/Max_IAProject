#include "stdafx.h"
#include "WindowTime.h"

void CWindowTime::init()
{
	m_clock.restart();
}

void CWindowTime::update()
{
	m_frameTime = m_clock.restart();
}

void CWindowTime::destroy()
{
}

float CWindowTime::getFrameTime()
{
	return m_frameTime.asSeconds();
}

CWindowTime::CWindowTime()
{
	init();
}


CWindowTime::~CWindowTime()
{
	destroy();
}
