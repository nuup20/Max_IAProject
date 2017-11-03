#pragma once
#include "BoidState.h"
class CPursuit :
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CPursuit(CBoid* myBoid) : CBoidState(BOIDSTATE::kPursuit, myBoid) {}
	~CPursuit();
};

