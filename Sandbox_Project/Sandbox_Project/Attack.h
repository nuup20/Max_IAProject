#pragma once
#include "BoidState.h"

class CAttack :
	public CBoidState
{
private:

public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CAttack(CSoldier* mySoldier);
	~CAttack();
};

