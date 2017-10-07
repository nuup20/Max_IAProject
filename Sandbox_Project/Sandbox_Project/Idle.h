#pragma once
#include "State.h"
class CIdle :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CIdle();
	~CIdle();
};

