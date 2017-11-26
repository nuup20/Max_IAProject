#pragma once
#include "State.h"
#include "Vector3.h"

class CSoldier;

class CBoidState :
	public CState
{
protected:
	CSoldier*	m_Soldier;

public:
	virtual void onEnter() {}
	virtual unsigned int update(void* pObject) { return 0; }
	virtual void onExit() {}

	CBoidState(int id, CSoldier* myBoid) : CState(id) , m_Soldier(myBoid) {}
	virtual ~CBoidState(){}
};

