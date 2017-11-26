#include "stdafx.h"
#include "GameScene.h"

//GOs
#include "Soldier.h"
#include "Base.h"
#include "Obstacle.h"

//STATE MCHN
#include "Idle.h"
#include "Attack.h"
#include "ToBase.h"
#include "DefendLeader.h"

#define PP_WANDER_RADIUS	100.f	//Radio del Circulo proyectado (wander)

void CSoldier::init()
{
	//MAQUINA DE ESTADOS
	m_fsm.AddState(new CIdle(this));
	m_fsm.AddState(new CAttack(this));
	m_fsm.AddState(new CToBase(this));	
	m_fsm.AddState(new CDefendLeader(this));

	//DEBUG TEXT
	m_font.loadFromFile("fonts/arial.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(17);
	m_text.setFillColor(sf::Color::White);

	//DEFINIR PARAMATROS DEL SPRITE
	m_texture.loadFromFile("gameResources/sprites/spr_soldier_01.png");
	m_sprite.setTexture(m_texture, true);
	m_sprite.setPosition(m_position.x, m_position.y);	
	m_wanderCircle.setFillColor(sf::Color(255, 0, 0, 80));
	m_wanderCircle.setRadius(PP_WANDER_RADIUS);

	sf::FloatRect rect = m_sprite.getLocalBounds();
	m_sprite.setOrigin(rect.width * 0.5f, rect.height * 0.5f);
	this->setColor(255.f, 255.f, 255.f, 255.f);

	m_miniFlag_texture.loadFromFile("gameResources/sprites/spr_miniFlag_01.png");
	m_miniFlag_Sprite.setTexture(m_miniFlag_texture, true);
	m_miniFlag_Sprite.setColor((m_team == TEAM::kRed ? Color::Green : Color::Red));

	//PARAMETROS DE OBJETIVOS
	if (m_targetList.size() > 0)
	{
		m_targetList.clear();
	}
	for (unsigned int i = 0; i < (BOIDTARGET::kCount); ++i) {
		CGameObject* newGO = nullptr;
		m_targetList.push_back(newGO);
	}

	m_enemyBase = m_friendlyBase = nullptr;	
	vector<CBase*> baseList = m_gameScene->getObjs<CBase>();
	for (int i = 0; i < baseList.size(); ++i)
	{
		if (baseList[i]->baseTeam() == m_team)
		{
			m_friendlyBase = baseList[i];
		}
		else if (baseList[i]->baseTeam() != TEAM::kUndefined) {
			m_enemyBase = baseList[i];
		}
	}

	// VARIOS
	this->setDirection(1.f, 1.f);
	m_flagPower = false;

	//ENTRAR EN ESTADO INICIAL
	m_fsm.SetState(BOIDSTATE::kIdle);
}

void CSoldier::update()
{
	m_fsm.UpdateState(m_gameScene);

	m_steeringForce = 0.0f;
	m_steeringForce += seek() + flee() + arrive() + pursuit() + evade()
		+ obstacleAvoidance(m_gameScene->getObjsInArea<CObstacle>(m_position.x, m_position.y, BOID_VISION))
		+ separation(m_gameScene->getObjsInArea<CBoid>(m_position.x, m_position.y,BOID_VISION))
		+ defendTheLeader();

	if (m_isWander)
	{
		m_steeringForce += wander();
	}
	if (m_isFlocking)
	{
		m_steeringForce += flock((m_gameScene->getObjsInArea<CBoid>(m_position.x, m_position.y, BOID_RADIUS)));
	}

	if (std::fabsf(m_steeringForce.x) <= std::numeric_limits<float>::epsilon() &&
		std::fabsf(m_steeringForce.y) <= std::numeric_limits<float>::epsilon())
	{//El vector es inválido
		return;
	}

	CVector3 steerForceDir = m_steeringForce.normalized();
	m_direction = (m_direction + (steerForceDir * m_mass * m_gameScene->m_time.getFrameTime()));
	m_direction.normalize();
	m_steeringForce = m_steeringForce.truncate(m_velocity);
	m_position += (m_direction *  m_steeringForce.magnitud() * m_gameScene->m_time.getFrameTime());
	

	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setRotation(m_direction.degAngle());

	if (m_flagPower)
	{
		m_miniFlag_Sprite.setPosition(m_position.x + (BOID_RADIUS >> 1), m_position.y - (BOID_RADIUS >> 1));
	}
}

void CSoldier::render(RenderWindow & wnd)
{
	wnd.draw(m_sprite);
	if (m_flagPower)
	{
		wnd.draw(m_miniFlag_Sprite);
	}

	if (m_debug)
	{
		if (m_isWander)
		{
			wnd.draw(m_wanderCircle);
		}
		drawVector(m_position, m_direction, wnd, true);
		drawVector(m_position, m_steeringForce, wnd);
		drawVectorInfo(wnd);
	}
}

void CSoldier::destroy()
{
}

unsigned int CSoldier::soldierTeam()
{
	return m_team;
}

CBase * CSoldier::enemyBase()
{
	return m_enemyBase;
}

CBase * CSoldier::friendlyBase()
{
	return m_friendlyBase;
}

bool CSoldier::flagPower()
{
	return m_flagPower;
}

void CSoldier::setFlagPower(bool setFlag)
{
	m_flagPower = setFlag;
}

CSoldier * CSoldier::leaderInSight()
{
	vector<CSoldier*> soldierList = m_gameScene->getObjsInArea<CSoldier>(m_position.x,m_position.y, BOID_VISION);
	
	for (auto& soldier : soldierList)
	{
		if (soldier->soldierTeam() == m_team)
		{
			if (soldier->flagPower() && soldier != this)
			{
				return soldier;
			}
		}
	}
	return nullptr;
}

CFlag * CSoldier::enemyFlagInSight()
{
	vector<CFlag*> flag_list = objectsAtVisionRange<CFlag>();
	CFlag* enemyFlag = nullptr;
	
	for (unsigned int i = 0; i < flag_list.size(); ++i)
	{
		if (flag_list[i]->flagTeam() != m_team
			&& flag_list[i]->flagTeam() != TEAM::kUndefined)
		{
			enemyFlag = flag_list[i];
			break;
		}
	}	
	return enemyFlag;
}

CSoldier::CSoldier(CGameScene * gmScn, unsigned int team) : CBoid(gmScn), m_team(team), m_flagPower(false)	
{
	init();
}

CSoldier::~CSoldier()
{
}
