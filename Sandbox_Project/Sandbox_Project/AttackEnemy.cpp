#include "stdafx.h"
#include "AttackEnemy.h"
#include "Soldier.h"
#include "GameScene.h"

void CAttackEnemy::onEnter()
{
	m_enemySoldier = nullptr;
	m_Soldier->m_stateDebug = "Attack Enemy";
}

unsigned int CAttackEnemy::update(void * pObject)
{
	CGameScene*			gmscn = reinterpret_cast<CGameScene*>(pObject);
	
	// TENGO UN TARGET
	if (m_enemySoldier != nullptr) 
	{
		// ¿HE PERDIDO AL ENEMIGO DE MI RADIO DE VISIÓN?
		CVector3 vec_toEnemy = m_enemySoldier->m_position - m_Soldier->m_position;
		if (vec_toEnemy.magnitud() > m_Soldier->BOID_VISION)
		{
			// ENEMIGO PERDIDO
			m_enemySoldier = nullptr;
		}

		// ¿TENGO A UN ENEMIGO EN MI RANGO DE DISPARO?
		if (m_Soldier->enemyInSight())
		{
			// DISPARAR A LO PENDEJO
			m_Soldier->shootBullet();
		}
	}

	// NO TENGO TARGET
	if (m_enemySoldier == nullptr) 
	{
		// BUSCAR UN NUEVO ENEMIGO A LA VISTA.
		m_enemySoldier = m_Soldier->enemyInSight();

		if (m_enemySoldier != nullptr)
		{
			// HE ENCONTRADO UN NUEVO ENEMIGO
			m_Soldier->addNewTarget(m_enemySoldier, BOIDTARGET::kSeek);			
		}
		else
		{
			// NO HAY ENEMIGOS A LA VISTA
			m_Soldier->m_fsm.SetState(BOIDSTATE::kIdle);
		}
	}	
	return 0;
}

void CAttackEnemy::onExit()
{
	m_Soldier->removeTarget(BOIDTARGET::kSeek);	
}

CAttackEnemy::CAttackEnemy(CSoldier * mySoldier) : CBoidState(BOIDSTATE::kAttackEnemy,mySoldier)
{

}

CAttackEnemy::~CAttackEnemy()
{
}
