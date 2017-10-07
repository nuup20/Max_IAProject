#pragma once
#include <vector>
#include "State.h"

using std::vector;

class CFsm
{
public:
	vector<CState> stateList;

	CFsm();
	~CFsm();
};

