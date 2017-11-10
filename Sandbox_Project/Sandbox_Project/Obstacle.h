#pragma once
#include "RendObject.h"
class CObstacle : public CRendObject
{
private:

public:
	float	m_radius;

	void	setRadius(float radius);

	CObstacle();
	~CObstacle();
};

