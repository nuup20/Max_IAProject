#pragma once
#include "RendObject.h"
class CFlag :
	public CRendObject
{
private:	
	const unsigned short	m_radius;

	unsigned int	m_team;
	bool			m_enable;

public:
	void init();
	void render(RenderWindow& wnd);

	unsigned int flagTeam();
	bool		isEnable();
	void		setEnable(bool set);

	CFlag(unsigned int team);
	~CFlag();
};

