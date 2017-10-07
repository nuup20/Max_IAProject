#pragma once
#include "State.h"
class CBuild :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CBuild();
	~CBuild();
};

