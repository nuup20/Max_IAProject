#pragma once
#include "State.h"
class CPatrol :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CPatrol();
	~CPatrol();
};

