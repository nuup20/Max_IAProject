#pragma once
#include "RendObject.h"
class CBase :
	public CRendObject
{
private:
	unsigned int m_team;

public:
	void init();
	unsigned int baseTeam();

	CBase(unsigned int team);
	~CBase();
};

