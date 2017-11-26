#include "stdafx.h"
#include "Obstacle.h"


void CObstacle::setRadius(float radius)
{
	m_radius = radius;
}

CObstacle::CObstacle() : CRendObject(GOGROUP::kObstacle) , m_radius(1.0f)
{
	init();
}


CObstacle::~CObstacle()
{
}
