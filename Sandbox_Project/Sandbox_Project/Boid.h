#pragma once
#include "GameObject.h"

class CBoid : public CGameObject
{
public:

	void	init();
	void	update();
	void	render();
	void	destroy();

	

	CBoid();
	~CBoid();
};

