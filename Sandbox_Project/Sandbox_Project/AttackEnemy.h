#pragma once
#include "BoidState.h"

class CSoldier;
class CAttackEnemy :
	public CBoidState
{
private:
	CSoldier* m_enemySoldier;

public:
	void onEnter();
	unsigned int update(void* pObject);
	void onExit();

	CAttackEnemy(CSoldier* mySoldier);
	~CAttackEnemy();
};

