#pragma once
#include "State.h"
class CGather :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CGather();
	~CGather();
};

