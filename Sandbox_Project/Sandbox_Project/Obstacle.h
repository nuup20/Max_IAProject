#pragma once
#include "GameObject.h"
class CObstacle : public CGameObject
{
public:

	void	init();
	void	update();
	void	render(RenderWindow& wnd);
	void	destroy();

	CObstacle();
	~CObstacle();
};

