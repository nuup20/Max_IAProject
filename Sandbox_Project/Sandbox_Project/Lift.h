#pragma once
#include "State.h"
class CLift :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CLift();
	~CLift();
};

