#pragma once
#include "BoidState.h"
class CToBase :
	public CBoidState
{
private:
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CToBase(CSoldier* mySoldier);
	~CToBase();
};

