#pragma once
#include "BoidState.h"
class CDefendLeader :
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CDefendLeader(CSoldier * mySoldier);
	~CDefendLeader();
};

