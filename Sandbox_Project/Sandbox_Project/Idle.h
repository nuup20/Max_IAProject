#pragma once
#include "BoidState.h"

class CSoldier;
class CIdle :
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CIdle(CSoldier* mySoldier);
	~CIdle();
};

