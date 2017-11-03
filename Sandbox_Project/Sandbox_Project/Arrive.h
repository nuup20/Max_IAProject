#pragma once
#include "BoidState.h"

class CArrive :
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CArrive(CBoid* myBoid) : CBoidState(BOIDSTATE::kArrive, myBoid) {}
	~CArrive();
};

