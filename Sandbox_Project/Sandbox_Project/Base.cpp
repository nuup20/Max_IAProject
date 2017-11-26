#include "stdafx.h"
#include "Base.h"



void CBase::init()
{
	if (m_team == TEAM::kRed)
	{
		this->setSpriteDirectory("gameResources/sprites/spr_base_01.png");
	}
	else 
	{
		this->setSpriteDirectory("gameResources/sprites/spr_base_01.png");
	}
	this->setColor(255.f, 255.f, 255.f, 255.f);
}

unsigned int CBase::baseTeam()
{
	return m_team;
}

CBase::CBase(unsigned int team) : CRendObject(GOGROUP::kBase), m_team(team)
{
	init();
}

CBase::~CBase()
{
}
