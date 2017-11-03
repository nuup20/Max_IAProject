#pragma once
#include "BoidState.h"
class CEvade :
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CEvade(CBoid* myBoid) : CBoidState(BOIDSTATE::kEvade, myBoid) {}
	~CEvade();
};

