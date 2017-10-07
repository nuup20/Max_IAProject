#pragma once
#include "State.h"
class CLand :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CLand();
	~CLand();
};

