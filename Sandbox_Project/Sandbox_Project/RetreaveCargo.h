#pragma once
#include "State.h"
class CRetreaveCargo :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CRetreaveCargo();
	~CRetreaveCargo();
};

