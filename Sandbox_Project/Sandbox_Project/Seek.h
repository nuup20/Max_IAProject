#pragma once
#include "BoidState.h"

class CSeek : 
	public CBoidState
{
public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CSeek(CBoid* myBoid) : CBoidState(BOIDSTATE::kSeek,myBoid){}
	~CSeek();
};

