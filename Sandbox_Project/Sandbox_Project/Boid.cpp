#include "stdafx.h"
#include "Boid.h"

#define	PI					3.141592
#define MAG_SEEK			3
#define RADIUS_FlEE			5 
#define RADIUS_ARRIVE		200.f	
#define	PP_WANDER_DIST		2	//Distancia entre el Puntro proyectado y posicion (wander)
#define PP_WANDER_RADIUS	2	//Radio del Circulo proyectado (wander)
#define PP_WANDER_APERTURE	30	//Angulo de apertura en grados (wander)
#define NODE_RADIUS			2
#define VELOCITY			10

void CBoid::init() {
	m_shape.setRadius(10.f);
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setPosition(m_position.x, m_position.y);
	pathIndex = 0;
}

void CBoid::update()
{	
	transform();
	m_shape.setPosition(m_position.x, m_position.y);
}

void CBoid::render(RenderWindow& wnd)
{	
	wnd.draw(m_shape);
}

void CBoid::destroy()
{
}

CVector3 CBoid::seek(int x, int y)
{
	CVector3 desired_Velocity = (CVector3(x, y) - m_position).normalized() * VELOCITY;	
	return desired_Velocity - (m_direction * VELOCITY);
}

CVector3 CBoid::flee(int x, int y)
{	
	if ((CVector3(x, y) - m_position).magnitud() < RADIUS_FlEE)
		return seek(x, y) *-1;
	else
		return CVector3(0, 0);
}

CVector3 CBoid::arrive(int x, int y)
{
	CVector3 desired_Velocity = (CVector3(x, y) - m_position).normalized() * VELOCITY;	
	if ((CVector3(x, y) - m_position).magnitud() < RADIUS_ARRIVE)
		desired_Velocity = desired_Velocity * ((CVector3(x, y) - m_position).magnitud() / RADIUS_ARRIVE);	
	return desired_Velocity -(m_direction * VELOCITY);
}

CVector3 CBoid::pursuit(CVector3 pos, CVector3 dir, float speed) {
	float t = (pos - m_position).magnitud() / VELOCITY;
	CVector3 futurePos = pos + (dir * speed * t);
	return seek(futurePos.x,futurePos.y);
}

CVector3 CBoid::evade(CVector3 pos, CVector3 dir, float speed) {
	float t = (pos - m_position).magnitud() / VELOCITY;
	CVector3 futurePos = pos + (dir * speed * t);
	return flee(futurePos.x, futurePos.y);
}

CVector3 CBoid::wander() {
	CVector3 pp = m_position + (m_direction * PP_WANDER_DIST);
	float f_wAp = (rand() % PP_WANDER_APERTURE) * (PI / 180);
	float f_wPhi = (atan(m_direction.y / m_direction.x) - (f_wAp *0.5)) + f_wAp;
	pp.x += PP_WANDER_RADIUS * cos(f_wPhi);
	pp.y += PP_WANDER_RADIUS * sin(f_wPhi);
	return (pp - m_position);
}

CVector3 CBoid::followPath()
{
	if (pathIndex >= nodes.size())
		return CVector3();
	if (pathIndex == 0)
		return seek(nodes[pathIndex].x, nodes[pathIndex].y);

	CVector3 agentDist = m_position - nodes[pathIndex - 1];
	CVector3 nodeDist = nodes[pathIndex] - nodes[pathIndex - 1];
	CVector3 pathForce = (nodeDist * dot(nodeDist, agentDist)) - agentDist;
	CVector3 nodeForce = nodes[pathIndex] - m_position;
	
	if ((nodes[pathIndex] - m_position).magnitud() <= NODE_RADIUS)
		++pathIndex;

	return nodeForce + pathForce;
}

CVector3 CBoid::followPath(vector<CVector3>& nodeList, float index)
{
	if (index >= nodeList.size())
		return CVector3();
	if (index == 0)
		return seek(nodeList[index].x, nodeList[index].y);

	CVector3 agentDist = m_position - nodeList[index - 1];
	CVector3 nodeDist = nodeList[index] - nodeList[index - 1];
	CVector3 pathForce = (nodeDist * dot(nodeDist, agentDist)) - agentDist;
	CVector3 nodeForce = nodeList[index] - m_position;

	return nodeForce + pathForce;
}

void CBoid::setDirection(int x, int y)
{
	m_direction.x = x;
	m_direction.y = y;	
}

void CBoid::setShapeColor(int r, int g, int b, int a)
{
	m_shape.setFillColor(sf::Color(r, g, b, a));
}

void CBoid::transform()
{	
	CVector3 res_Force = ((m_direction * VELOCITY) + (arrive(640, 360) * 0.001));
	m_direction = res_Force.normalized();
	m_position = m_position + (res_Force.truncate(VELOCITY) * 0.01f);
}

CBoid::CBoid()
{
}

CBoid::~CBoid()
{
	destroy();
}
