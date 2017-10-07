#pragma once
#include "State.h"
class CAttack :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CAttack();
	~CAttack();
};

