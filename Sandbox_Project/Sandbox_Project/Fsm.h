#pragma once
#include <vector>
#include "State.h"

using std::vector;

class CObject;

namespace STATES
{
	enum E
	{
		kIdle = 0,
		kAttack,
		kBuild,
		kNumStates
	};
}

class CFsm
{
public:
	vector<CState*> m_stateList;
	CState* m_aciveState;

	void AddState(CState* pState, bool deleteOnExit = true);
	int SetState(unsigned int s);
	int UpdateState(void* pObject);

	CFsm();
	~CFsm();
};

