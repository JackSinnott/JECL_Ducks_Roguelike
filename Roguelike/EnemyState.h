#pragma once
#include "Globals.h"

class EnemyState
{
public:
	EnemyState(EnemyType t_enemyType, sf::Sprite* t_enemy) { m_enemyType = t_enemyType, m_enemy = t_enemy; }
	virtual void processMovement() = 0;
private:
	EnemyType m_enemyType;
	sf::Sprite* m_enemy;
};
