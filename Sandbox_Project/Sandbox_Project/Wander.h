#pragma once
#include "BoidState.h"

class CWander :
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CWander(CBoid* myBoid) : CBoidState(BOIDSTATE::kWander, myBoid) {}
	~CWander();
};

