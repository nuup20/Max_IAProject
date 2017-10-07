#pragma once
#include "State.h"
class CDead :
	public CState
{
public:

	void onEnter();
	void update();
	void onExit();

	CDead();
	~CDead();
};

