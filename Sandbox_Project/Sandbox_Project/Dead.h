#pragma once
#include "BoidState.h"
class CDead :
	public CBoidState
{
private:
	static const int m_timeToRespawn = 5;
	float m_timeCount;

public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CDead(CSoldier* mySoldier);
	~CDead();
};

