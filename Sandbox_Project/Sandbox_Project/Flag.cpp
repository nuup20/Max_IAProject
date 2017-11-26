#include "stdafx.h"
#include "Flag.h"


void CFlag::init()
{
	if (m_team == TEAM::kRed)
	{
		this->setSpriteDirectory("gameResources/sprites/spr_red_flag.png");
	}
	else if (m_team == TEAM::kGreen)
	{
		this->setSpriteDirectory("gameResources/sprites/spr_green_flag.png");
	}
	else
	{
		this->setSpriteDirectory("gameResources/sprites/spr_green_flag.png");
	}	
	this->setColor(255.f, 255.f, 255.f, 255.f);
}

void CFlag::render(RenderWindow & wnd)
{
	if (m_enable) {
		wnd.draw(m_sprite);
	}	
}

unsigned int CFlag::flagTeam()
{
	return m_team;
}

bool CFlag::isEnable()
{
	return m_enable;
}

void CFlag::setEnable(bool set)
{
	m_enable = set;
}

CFlag::CFlag(unsigned int team) : CRendObject(GOGROUP::kFlag), m_team(team), m_radius(10), m_enable(true)
{
	init();
}


CFlag::~CFlag()
{
}
