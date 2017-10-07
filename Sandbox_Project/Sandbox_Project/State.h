#pragma once

class CState
{
public:

	virtual void onEnter();
	virtual void update();
	virtual void onExit();

	CState();
	virtual ~CState();
};

