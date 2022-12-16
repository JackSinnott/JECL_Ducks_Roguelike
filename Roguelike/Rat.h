#pragma once
#include "Globals.h"
#include "Enemy.h"

/// <summary>
/// The Rat enemy that inherits from the Enemy Class
/// </summary>
class Rat : public Enemy
{
public:
	/// <summary>
	/// Overload constructor for the rat that sets the position
	/// </summary>
	/// <param name="t_posX">Position of the players on the X-axis</param>
	/// <param name="t_posY">Position of the players on the Y-axis</param>
	Rat(float t_posX, float t_posY)
	{
		m_type = EnemyType::Rat;
		int xCoord = (int)t_posX - (int)t_posX % G_CELL_SIZE + G_CELL_SIZE / 2;
		int yCoord = (int)t_posY - (int)t_posY % G_CELL_SIZE + G_CELL_SIZE / 2;
		m_enemy.setOrigin(G_CELL_SIZE / 2, G_CELL_SIZE / 2);
		m_enemy.setPosition(sf::Vector2f(xCoord, yCoord));
		row = (xCoord - G_CELL_SIZE / 2) / G_CELL_SIZE;
		col = (yCoord - G_CELL_SIZE / 2) / G_CELL_SIZE;

		m_enemyTexture = TextureManager::Acquire(ITEMS_TEXTURE);

		m_enemy.setTexture(*m_enemyTexture);

		m_enemy.setTextureRect(sf::IntRect{ 64,160,16,16 });

		m_enemy.setOrigin(m_enemy.getTextureRect().width / 2.0f,
			m_enemy.getTextureRect().height / 2.0f);
		m_enemy.setScale(2.0f, 2.0f);

		CombatSystem::PushBackEnemyStats(&health, xp);

	}
	sf::IntRect spriteRect = sf::IntRect{ 0,160,16,16 };
private:
	/// <summary>
	/// Overrides the move function with the Rats movement logic
	/// </summary>
	/// <param name="t_playerPos">The Position on the grid of the player</param>
	/// <param name="t_playerRoom">The room the player is in</param>
	/// <param name="t_enemyRoom">The room the enemy is in</param>
	void move(sf::Vector2i t_playerPos, int t_playerRoom, int t_enemyRoom) override
	{
		if (t_playerRoom != t_enemyRoom)
		{
			randomMovement();
		}
		else if (abs(t_playerPos.x - col) > 1 || abs(t_playerPos.y - row) > 1)
		{
			moveTowardsPlayer(t_playerPos);
		}
		else
		{
			CalculateDamageToPlayer(1);
		}
	}
};
