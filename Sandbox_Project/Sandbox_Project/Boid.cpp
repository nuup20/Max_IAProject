#include "stdafx.h"
#include "Boid.h"

#define	PI					3.141592
#define MAG_SEEK			3
#define RADIUS_FlEE			500.f 
#define RADIUS_ARRIVE		200.f	
#define	PP_WANDER_DIST		350.f	//Distancia entre el Puntro proyectado y posicion (wander)
#define PP_WANDER_RADIUS	300.f	//Radio del Circulo proyectado (wander)
#define PP_WANDER_APERTURE	180		//Angulo de apertura en grados (wander)
#define NODE_RADIUS			2
#define BOID_RADIUS			1
#define BOID_VISION			5
#define BOID_SEPARATION		5
#define BOID_REPULSION_FORCE 10

void CBoid::init() {

	m_wndTime.init();

	m_texture.loadFromFile("textures/default/spr_boid_01.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setColor(sf::Color::Green);
	
	sf::FloatRect rect = m_sprite.getLocalBounds();
	m_sprite.setOrigin(rect.width * 0.5f, rect.height * 0.5f);	

	if(m_targetList.size() > 0)
	{
		m_targetList.clear();
	}
	for (unsigned int i = 0; i < (BOIDTARGET::kCount); ++i) {
		CGameObject* newGO = nullptr;
		m_targetList.push_back(newGO);
	}
}

void CBoid::update()
{	
	m_wndTime.update();
	
	m_steeringForce = 0.0f;
	m_steeringForce += seek() + flee() + arrive() + pursuit() + evade() + followPath();
	if (m_isWander) 
	{
		m_steeringForce += wander();
	}

	if (std::fabsf(m_steeringForce.x) <= std::numeric_limits<float>::epsilon() &&
		std::fabsf(m_steeringForce.y) <= std::numeric_limits<float>::epsilon())
	{//El vector es inv�lido
		return;
	}

	CVector3 steerForceDir = m_steeringForce.normalized();

	float mass = 1.0f;

	m_direction = (m_direction + (steerForceDir * mass * m_wndTime.getFrameTime())) ;
	m_direction.normalize();
	m_position += (m_direction * m_steeringForce.truncate(m_velocity).magnitud() * m_wndTime.getFrameTime());
	
	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setRotation(m_direction.degAngle());
}

void CBoid::render(RenderWindow& wnd)
{	
	wnd.draw(m_sprite);	
}

void CBoid::destroy()
{
	m_wndTime.destroy();
}

CVector3 CBoid::seek(float x, float y)
{
	return (CVector3(x, y) - m_position).normalized() * SEEK_FORCE;	
}

CVector3 CBoid::seek()
{
	if (!m_targetList[BOIDTARGET::kSeek])
		return CVector3();
	return seek(m_targetList[BOIDTARGET::kSeek]->m_position.x, m_targetList[BOIDTARGET::kSeek]->m_position.y);
}

CVector3 CBoid::flee(float x, float y)
{	
	if ((CVector3(x, y) - m_position).magnitud() < RADIUS_FlEE)
		return seek(x, y) *-1;
	else
		return CVector3();
}

CVector3 CBoid::flee()
{
	if(!m_targetList[BOIDTARGET::kFlee])
		return CVector3();
	return flee(m_targetList[BOIDTARGET::kFlee]->m_position.x, m_targetList[BOIDTARGET::kFlee]->m_position.y);
}

CVector3 CBoid::arrive(float x, float y)
{
	CVector3 force = (CVector3(x, y) - m_position).normalized() * m_velocity;
	if ((CVector3(x, y) - m_position).magnitud() < RADIUS_ARRIVE)
		force *= ((CVector3(x, y) - m_position).magnitud() / RADIUS_ARRIVE);
	return force;
}

CVector3 CBoid::arrive()
{
	if(!m_targetList[BOIDTARGET::kArrive])
		return CVector3();
	return arrive(m_targetList[BOIDTARGET::kArrive]->m_position.x, m_targetList[BOIDTARGET::kArrive]->m_position.y);
}

CVector3 CBoid::pursuit(CVector3 position, CVector3 directeion, float speed)
{	
	float t = (position - m_position).magnitud() / m_velocity;	
	CVector3 futurePos = position + (directeion * speed * t);
	return seek(futurePos.x, futurePos.y);
}

CVector3 CBoid::pursuit() {
	if (!m_targetList[BOIDTARGET::kPursuit]) {
		return CVector3();
	}
	CBoid* obj = reinterpret_cast<CBoid*>(m_targetList[BOIDTARGET::kPursuit]);
	return pursuit(obj->m_position, obj->getDirection(), obj->getVelocity());	
}

CVector3 CBoid::evade(CVector3 position, CVector3 directeion, float speed)
{
	float t = (position - m_position).magnitud() / m_velocity;
	CVector3 futurePos = position + (directeion * speed * t);
	return flee(futurePos.x, futurePos.y);
}

CVector3 CBoid::evade() {
	if (!m_targetList[BOIDTARGET::kEvade]){
		return CVector3(0, 0, 0);
	}	
	CBoid* obj = reinterpret_cast<CBoid*>(m_targetList[BOIDTARGET::kEvade]);
	return evade(obj->m_position, obj->getDirection(), obj->getVelocity());
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
	if (m_pathIndex >= m_nodes.size())
		return CVector3();
	if (m_pathIndex == 0)
		return seek(m_nodes[m_pathIndex]->m_position.x, m_nodes[m_pathIndex]->m_position.y);

	CVector3 agentDist = m_position - m_nodes[m_pathIndex - 1]->m_position;
	CVector3 nodeDist = m_nodes[m_pathIndex]->m_position - m_nodes[m_pathIndex - 1]->m_position;
	CVector3 pathForce = (nodeDist * dot(nodeDist, agentDist)) - agentDist;
	CVector3 nodeForce = m_nodes[m_pathIndex]->m_position - m_position;
	
	if ((m_nodes[m_pathIndex]->m_position - m_position).magnitud() <= NODE_RADIUS)
		++m_pathIndex;

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

void CBoid::setDirection(float x, float y, float z)
{
	m_direction.x = x;
	m_direction.y = y;	
	m_direction.z = z;
}

CVector3 CBoid::getDirection()
{
	return m_direction;
}

void CBoid::setVelocity(float vel)
{
	m_velocity = vel;
}

float CBoid::getVelocity()
{
	return m_velocity;
}

void CBoid::setSpriteDirectory(string directory)
{
	if (!m_texture.loadFromFile(directory))
		m_texture.loadFromFile("textures/default/spr_boid_01.png");
	m_sprite.setTexture(m_texture, true);
	
	sf::FloatRect rect = m_sprite.getLocalBounds();
	m_sprite.setOrigin(rect.width * 0.5f, rect.height * 0.5f);
}

void CBoid::setSpriteColor(int r, int g, int b, int a)
{
	m_sprite.setColor(sf::Color(r, g, b, a));
}

void CBoid::scaleSprite(float scale)
{
	m_sprite.scale(scale,scale);
}

void CBoid::addObstacleNode(CGameObject & newNode)
{
	m_nodes.push_back(&newNode);
}

void CBoid::setSteeringForce(CVector3 force)
{
	m_steeringForce = force;
}

CVector3 CBoid::getTargetPosition(unsigned int targetIndex)
{
	if (targetIndex >= m_targetList.size()) {
		return CVector3();
	}
	if (m_targetList[targetIndex] != nullptr) 
	{
		return CVector3();
	}
	return m_targetList[targetIndex]->m_position;	
}

bool CBoid::addNewTarget(CGameObject* go, unsigned int targetType, bool _deleteGO)
{
	if (targetType >= m_targetList.size()) {
		return false;
	}
	if (_deleteGO) {
		if (m_targetList[targetType] != nullptr)
		{
			delete m_targetList[targetType];
		}
	}
	m_targetList[targetType] = go;
	return true;
}

bool CBoid::removeTarget(unsigned int targetType, bool _deleteGO)
{
	return addNewTarget(nullptr, targetType, _deleteGO);
}

void CBoid::setWander(bool b)
{
	m_isWander = b;
}

CBoid::CBoid() : m_pathIndex(0), m_velocity(0), m_isWander(false)
{
	init();
}

CBoid::~CBoid()
{
	destroy();
}
