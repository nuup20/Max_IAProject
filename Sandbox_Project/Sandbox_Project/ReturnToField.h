#pragma once
#include "BoidState.h"
#include "GameObject.h"

class CReturnToField :
	public CBoidState
{
private:
	CGameObject m_center;

public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CReturnToField(CSoldier* mySoldier);
	~CReturnToField();
};

