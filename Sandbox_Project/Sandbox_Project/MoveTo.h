#pragma once
#include "State.h"
class CMoveTo :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CMoveTo();
	~CMoveTo();
};

