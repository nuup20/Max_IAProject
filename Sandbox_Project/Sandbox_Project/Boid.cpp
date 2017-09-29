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
#define BOID_RADIUS			1
#define BOID_VISION			5
#define BOID_SEPARATION		5
#define BOID_REPULSION_FORCE 10
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
	float f_wPhi = (atan(m_direction.y / m_direction.x) - ((PP_WANDER_APERTURE >> 1) * PI / 180)) + f_wAp;
	pp.x += PP_WANDER_RADIUS * cos(f_wPhi);
	pp.y += PP_WANDER_RADIUS * sin(f_wPhi);
	return (pp - m_position);
}

CVector3 CBoid::followPath()
{
	if (pathIndex >= nodes.size())
		return CVector3();
	if (pathIndex == 0)
		return seek(nodes[pathIndex]->m_position.x, nodes[pathIndex]->m_position.y);

	CVector3 agentDist = m_position - nodes[pathIndex - 1]->m_position;
	CVector3 nodeDist = nodes[pathIndex]->m_position - nodes[pathIndex - 1]->m_position;
	CVector3 pathForce = (nodeDist * dot(nodeDist, agentDist)) - agentDist;
	CVector3 nodeForce = nodes[pathIndex]->m_position - m_position;
	
	if ((nodes[pathIndex]->m_position - m_position).magnitud() <= NODE_RADIUS)
		++pathIndex;

	return nodeForce + pathForce;
}

CVector3 CBoid::followPath(vector<CGameObject*>& nodeList, float index)
{
	if (index >= nodeList.size())
		return CVector3();
	if (index == 0)
		return seek(nodeList[index]->m_position.x, nodeList[index]->m_position.y);

	CVector3 agentDist = m_position - nodeList[index - 1]->m_position;
	CVector3 nodeDist = nodeList[index]->m_position - nodeList[index - 1]->m_position;
	CVector3 pathForce = (nodeDist * dot(nodeDist, agentDist)) - agentDist;
	CVector3 nodeForce = nodeList[index]->m_position - m_position;

	return nodeForce + pathForce;
}

CVector3 CBoid::obstacleAvoidance(vector<CObstacle*>& obstacles)
{
	CVector3	visionVec = this->m_direction * BOID_VISION;
	CVector3	vect_ObsToVision, vect_AgentToObs;
	CGameObject* primaryObstacle = NULL;
	float		refEsc = BOID_VISION;
	float		dotEsc = 0;

	for (int i = 0; i < obstacles.size(); ++i) {
		vect_AgentToObs = (*obstacles[i]).m_position - this->m_position;
		dotEsc = vect_AgentToObs.dot(visionVec);
		if ( dotEsc > 0 && dotEsc <= 1 && dotEsc <= refEsc) {
			vect_ObsToVision = (visionVec * dotEsc) - vect_AgentToObs;
			if (((vect_ObsToVision).magnitud() - (*obstacles[i]).m_radius) <= (BOID_RADIUS * 0.5f)) {
				primaryObstacle = obstacles[i];
			}
		}
	}

	if (primaryObstacle != NULL) {
		vect_AgentToObs = (*primaryObstacle).m_position - this->m_position;
		dotEsc = vect_AgentToObs.dot(visionVec);
		vect_ObsToVision = (visionVec * dotEsc) - vect_AgentToObs;
		return vect_ObsToVision * 999999.f;
	}

	return CVector3(0,0,0);
}

CVector3 CBoid::avargeDirection(vector<CBoid*>& boidList)
{
	CVector3 pDirection(0,0,0);
	for (int i = 0; i < boidList.size(); ++i) {
		pDirection += (*boidList[i]).m_direction;
	}
	return (pDirection / boidList.size()).normalized();
}

CVector3 CBoid::cohesion(vector<CBoid*>& boidList)
{
	CVector3 pPosition(0, 0, 0);
	for (int i = 0; i < boidList.size(); ++i) {
		pPosition += (*boidList[i]).m_direction;
	}
	pPosition /= boidList.size();
	return seek(pPosition.x, pPosition.y);
}

CVector3 CBoid::separation(vector<CBoid*>& boidList) {
	CVector3 separationForce(0, 0, 0);
	CVector3 vectToObject;
	for (int i = 0; i < boidList.size(); ++i) {
		vectToObject = m_position - boidList[i]->m_position;
		if (vectToObject.magnitud() <= BOID_SEPARATION)
			separationForce += vectToObject.normalized() * ((1 - (vectToObject.magnitud() / BOID_SEPARATION))*BOID_REPULSION_FORCE);		
	}
	return separationForce;
}

CVector3 CBoid::flock(vector<CBoid*>& boidList)
{
	return separation(boidList) + cohesion(boidList) + avargeDirection(boidList);
}

CVector3 CBoid::followTheLeader(CBoid& leader, float proyectionMgn, vector<CBoid*>& boidList)
{
	CVector3 seekPoint = leader.m_position - (leader.m_direction * proyectionMgn);
	return separation(boidList) + seek(seekPoint.x,seekPoint.y) + (leader.m_direction * MAG_SEEK) + flee(leader.m_position.x, leader.m_position.y);
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

void CBoid::addObstacleNode(CGameObject & newNode)
{
	nodes.push_back(&newNode);
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
