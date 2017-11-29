#pragma once
#include "BoidState.h"
class CDefendBase :
	public CBoidState
{
private:
	static const int DEFENCE_RANGE = 560;
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CDefendBase(CSoldier* mySoldier);
	~CDefendBase();
};

