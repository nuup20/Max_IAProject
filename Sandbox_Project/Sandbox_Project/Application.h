#pragma once
#include "World.h"

class CApplication
{
protected:
	CWorld	m_world;	

public:
	virtual void	init();
	virtual void	update();
	virtual void	render();
	virtual void	destroy();
	virtual int		run();

	CApplication();
	virtual ~CApplication();
};

