#pragma once
#include "BoidState.h"
class CFlee :
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CFlee(CBoid* myBoid) : CBoidState(BOIDSTATE::kFlee, myBoid) {}
	~CFlee();
};

