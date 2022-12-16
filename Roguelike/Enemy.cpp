#include "Enemy.h"

/// <summary>
/// Empty constructor, is to be overridden by child classes
/// </summary>
Enemy::Enemy()
{
}

/// <summary>
/// Updates the enemy, checks if the enemy has health and if so does the move action
/// </summary>
/// <param name="t_playerPos">The Position on the grid of the player</param>
/// <param name="t_playerRoom">The room the player is in</param>
/// <param name="t_enemyRoom">The room the enemy is in</param>
void Enemy::update(sf::Vector2i t_playerPos, int t_playerRoom, int t_enemyRoom)
{
	if (health > 0)
	{
		move(t_playerPos, t_playerRoom, t_enemyRoom);
	}
}

/// <summary>
/// Calculates the hit chance the enemy has on the player,
/// and then if they hit, calculates the damage to the player and applies it.
/// </summary>
/// <param name="t_playerAC">The player's armour class.</param>
void Enemy::CalculateDamageToPlayer(int t_playerAC)
{
	bool hitPlayer = CombatSystem::BattleEquation(t_playerAC);

	if (hitPlayer)
	{
		std::cout << "The enemy hit you!" << std::endl;
		CombatSystem::HurtPlayer(GetDamage());
	}

	else
	{
		std::cout << "The enemy missed you." << std::endl;
	}
}

/// <summary>
/// Draws the Enemy to the screen.
/// </summary>
/// <param name="t_window">The window to draw to.</param>
void Enemy::render(sf::RenderWindow& t_window)
{
	if (health > 0)
	{
		t_window.draw(m_enemy);
	}
}

/// <summary>
/// Returns the armour class of this enemy - aka how hard it is to hit.
/// </summary>
/// <returns>The AC of this Enemy.</returns>
int Enemy::GetArmourClass()
{
	return m_armourClass;
}

/// <summary>
/// Calculates how much damage this enemy would cause to it's target, and return it.
/// </summary>
/// <returns>The damage dealt by this enemy.</returns>
int Enemy::GetDamage()
{
	int damage = CombatSystem::RollD8();
	return damage;
}

/// <summary>
/// This behaviour moves the enemy randomly only avoiding walls
/// </summary>
void Enemy::randomMovement()
{
	sf::Vector2f pos = m_enemy.getPosition();
	int direction = rand() % 4;
	switch (direction)
	{
	case 0:
		if (canWeMoveUp())
		{
			row--;
			pos.y -= G_CELL_SIZE;
		}
		break;
	case 1:
		if (canWeMoveRight())
		{
			col++;
			pos.x += G_CELL_SIZE;
		}
		break;
	case 2:
		if (canWeMoveDown())
		{
			row++;
			pos.y += G_CELL_SIZE;
		}
		break;
	case 3:
		if (canWeMoveLeft())
		{
			col--;
			pos.x -= G_CELL_SIZE;
		}
		break;
	}
	m_enemy.setPosition(pos);
}

/// <summary>
/// This behaviour moves the Enemy towards the player, if theres a wall it stops in its tracks
/// </summary>
/// <param name="t_playerPos">The position on the grid of the player</param>
void Enemy::moveTowardsPlayer(sf::Vector2i t_playerPos)
{
	sf::Vector2f pos = m_enemy.getPosition();
	if (abs(t_playerPos.x - col) > 1)
	{
		if (col > t_playerPos.x)
		{
			if (canWeMoveLeft())
			{
				col--;
				pos.x -= G_CELL_SIZE;
			}
		}
		else if (col < t_playerPos.x)
		{
			if (canWeMoveRight())
			{
				col++;
				pos.x += G_CELL_SIZE;
			}
		}
	}
	if (abs(t_playerPos.y - row) > 1)
	{
		if (row > t_playerPos.y)
		{
			if (canWeMoveUp())
			{
				row--;
				pos.y -= G_CELL_SIZE;
			}
		}
		else if (row < t_playerPos.y)
		{
			if (canWeMoveDown())
			{
				row++;
				pos.y += G_CELL_SIZE;
			}
		}
	}
	m_enemy.setPosition(pos);
}
