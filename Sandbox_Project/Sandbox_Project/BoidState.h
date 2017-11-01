#pragma once
#include "State.h"

class CBoid;

class CBoidState :
	public CState
{
protected:
	CBoid*	m_Boid;

public:
	virtual void onEnter() {}
	virtual unsigned int update(void* pObject) { return 0; }
	virtual void onExit() {}

	CBoidState(int id, CBoid* myBoid) : CState(id) , m_Boid(myBoid) {}
	virtual ~CBoidState(){}
};

