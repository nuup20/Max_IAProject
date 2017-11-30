#include "stdafx.h"
#include "GameScene.h"

//GOs
#include "Soldier.h"
#include "Base.h"
#include "Obstacle.h"
#include "Bullet.h"

//STATE MCHN
#include "Idle.h"
#include "Attack.h"
#include "ToBase.h"
#include "ReturnToField.h"
#include "DefendLeader.h"
#include "DefendBase.h"
#include "AttackEnemy.h"
#include "Dead.h"

#define PP_WANDER_RADIUS	100.f	//Radio del Circulo proyectado (wander)

void CSoldier::init()
{
	//MAQUINA DE ESTADOS
	m_fsm.AddState(new CIdle(this));
	m_fsm.AddState(new CAttack(this));
	m_fsm.AddState(new CToBase(this));	
	m_fsm.AddState(new CReturnToField(this));
	m_fsm.AddState(new CDefendLeader(this));
	m_fsm.AddState(new CDefendBase(this));
	m_fsm.AddState(new CAttackEnemy(this));
	m_fsm.AddState(new CDead(this));

	//DEBUG TEXT
	m_font.loadFromFile("fonts/arial.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(17);
	m_text.setFillColor(sf::Color::White);

	//DEFINIR PARAMATROS DEL SPRITE
	m_texture.loadFromFile("gameResources/sprites/" + static_cast<string>(m_team == TEAM::kRed ? "spr_soldier_red.png" : "spr_soldier_green.png"));	
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
	if (m_team == TEAM::kRed)
	{
		this->setDirection(1.f, 0.f);
	}
	else
	{
		this->setDirection(-1.f, 0.f);
	}
	
	m_flagPower = false;
	m_shootTimeCnt = 0;	

	//ENTRAR EN ESTADO INICIAL
	m_fsm.SetState(BOIDSTATE::kIdle);
}

void CSoldier::update()
{
	// RECARGAR EL ESTADO EN EL QUE SE ENCUENTRA.
	m_fsm.UpdateState(m_gameScene);
	
	if (!m_isEnable)
	{
		// NO ESTÁ ACTIVADO, SOLO DEFINIR LA POSICIÓN DEL SPRITE.
		m_sprite.setPosition(m_position.x, m_position.y);		
		return;
	}

	// AUMENTAR EL CONTADOR DE TIEMPO;
	m_shootTimeCnt += m_gameScene->m_time.getFrameTime();	

	// CALCULO DE FUERZAS
	m_steeringForce = 0.0f;	
	m_steeringForce += seek() + flee() + arrive() + pursuit() + evade()	+ defendTheLeader();

	if (m_isMoving && !outOfField())
	{
		// SI ME ESTOY MOVIENDO, EVITAR OBSTÁCULOS Y SEPARARME DE MIS COMPAS.
		m_steeringForce += obstacleAvoidance(m_gameScene->getObjsInArea<CObstacle>(m_position.x, m_position.y, BOID_VISION))
						+ separation(m_gameScene->getObjsInArea<CBoid>(m_position.x, m_position.y, BOID_VISION));
	}
	if (m_isWander)
	{
		m_steeringForce += wander();
	}

	if (std::fabsf(m_steeringForce.x) <= std::numeric_limits<float>::epsilon() &&
		std::fabsf(m_steeringForce.y) <= std::numeric_limits<float>::epsilon())
	{//El vector es inválido
		return;
	}

	CVector3 steerForceDir = m_steeringForce.normalized();
	m_direction = (m_direction + (steerForceDir * m_mass * 2 * m_gameScene->m_time.getFrameTime()));
	m_direction.normalize();
	m_steeringForce = m_steeringForce.truncate(m_velocity);
	
	if (m_isMoving)
	{
		// APLICAR FUERZAS SOLO SI ESTOY EN MOVIMIENTO.
		m_position += (m_direction *  m_steeringForce.magnitud() * m_gameScene->m_time.getFrameTime());
	}	

	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setRotation(m_direction.degAngle());

	// REVISAR SI UNA BALA ENEMIGA ME HA GOLPEADO
	vector<CBullet*> bulletsList = m_gameScene->getObjsInArea<CBullet>(m_position.x, m_position.y, BOID_RADIUS);
	for (auto bullet : bulletsList)
	{
		if (bullet->m_team != m_team)
		{
			// RAYOS, ESTOY MUERTO.
			m_fsm.SetState(BOIDSTATE::kDead);
			m_gameScene->destroyObject(bullet);
			break;
		}			
	}	

	// SI POSEE LA BANDERA, DEFINIR POSICIÓN DEL SPRITE.
	if (m_flagPower)
	{
		m_miniFlag_Sprite.setPosition(m_position.x + (BOID_RADIUS >> 1), m_position.y - (BOID_RADIUS >> 1));
	}	

	// SI EL SOLDADO ESTÁ FUERA DEL CAMPO DE BATALLA.
	if (outOfField())
	{
		m_fsm.SetState(BOIDSTATE::kToField);
	}
	
}

void CSoldier::render(RenderWindow & wnd)
{
	if (!m_isEnable)
	{
		return;
	}

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

bool CSoldier::outOfField()
{
	// SI EL SOLDADO SALE DEL CAMPO DE BATALLA
	if (m_position.x < 20 || m_position.x > 1920 - 20 || m_position.y < 20 || m_position.y > 1080 - 20)
	{
		return true;
	}
	return false;
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

CSoldier * CSoldier::enemyInSight()
{
	vector<CSoldier*> soldierList = m_gameScene->getObjsInArea<CSoldier>(m_position.x, m_position.y, BOID_VISION);
	for (auto soldier : soldierList)
	{
		if (soldier->m_team != m_team)
		{
			CVector3 vec_distToSoldier = soldier->m_position - m_position;
			if (dot(vec_distToSoldier, m_direction) > 0)
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

bool CSoldier::shootBullet()
{
	if (m_shootTimeCnt > m_timeToShoot)
	{
		m_shootTimeCnt = 0;

		CBullet* bullet = new CBullet(m_position,m_direction,m_gameScene,m_team);
		m_gameScene->addNewObject(bullet);
		return true;
	}
	return false;
}

CVector3 CSoldier::sceneLitimsForce()
{
	CVector3 pointPos = m_position + (m_direction * BOID_VISION);
	CVector3 force;
	
	if (pointPos.x < 0)
	{
		force.x = 1;		
	}
	else if (pointPos.x > 1920)
	{
		force.x = -1;		
	}
	if (pointPos.y < 0)
	{
		force.y = 1;		
	}
	else if (pointPos.y > 1080)
	{
		force.y = -1;		
	}
	force *= 9999999.f;
	
	return force;
}

CSoldier::CSoldier(CGameScene * gmScn, unsigned int team) : CBoid(gmScn), m_team(team), m_flagPower(false), m_isMoving(true)
{
	init();
}

CSoldier::~CSoldier()
{
}
