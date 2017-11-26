// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

namespace SCENE_STATES
{
	enum E
	{
		kInvalid = 0,
		kMenu,
		kOptions,
		kGame,		
		kNumScenes
	};
}

namespace BOIDSTATE {
	enum e {
		kUndefined,
		kIdle,
		kAttack,
		kDefendLeader,
		kToBase,
		kCount
	};
}

namespace TEAM {
	enum t {
		kUndefined,
		kGreen,
		kRed,
		kCount
	};
}

// TODO: reference additional headers your program requires here
