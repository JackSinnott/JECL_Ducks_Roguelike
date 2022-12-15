#pragma once
#include "Globals.h"
#include "Enemy.h"

class Bat : public Enemy
{
public:
	Bat(float t_posX, float t_posY)
	{
		m_type = EnemyType::Bat;
		int xCoord = (int)t_posX - (int)t_posX % G_CELL_SIZE + G_CELL_SIZE / 2;
		int yCoord = (int)t_posY - (int)t_posY % G_CELL_SIZE + G_CELL_SIZE / 2;
		m_enemy.setOrigin(G_CELL_SIZE / 2, G_CELL_SIZE / 2);
		m_enemy.setPosition(sf::Vector2f(xCoord, yCoord));
		row = (xCoord - G_CELL_SIZE / 2) / G_CELL_SIZE;
		col = (yCoord - G_CELL_SIZE / 2) / G_CELL_SIZE;

		m_enemyTexture = TextureManager::Acquire(ITEMS_TEXTURE);

		m_enemy.setTexture(*m_enemyTexture);

		m_enemy.setTextureRect(sf::IntRect{ 0,160,16,16 });

		m_enemy.setOrigin(m_enemy.getTextureRect().width / 2.0f,
			m_enemy.getTextureRect().height / 2.0f);
		m_enemy.setScale(2.0f, 2.0f);

		CombatSystem::PushBackEnemyStats(&health, xp);

	}
	sf::IntRect spriteRect = sf::IntRect{ 0,160,16,16 };
private:
	void move(sf::Vector2i t_playerPos, int t_playerRoom, int t_enemyRoom) override
	{
		if (abs(t_playerPos.x - col) > 1 || abs(t_playerPos.y - row) <= 1)
		{
			randomMovement();
		}
		else 
		{
			CalculateDamageToPlayer(1);
		}
	}
};
