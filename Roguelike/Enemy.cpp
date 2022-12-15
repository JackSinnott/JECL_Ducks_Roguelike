#include "Enemy.h"

std::unordered_map<EnemyType, sf::IntRect> Enemy::m_rects = std::unordered_map<EnemyType, sf::IntRect>(); // initialize

/// <summary>
/// Overloaded constructor of the Enemy.
/// </summary>
/// <param name="t_type">The type of Enemy this is.</param>
/// <param name="t_posX">The x position of the enemy.</param>
/// <param name="t_posY">The y position of the enemy.</param>
Enemy::Enemy(EnemyType t_type, float t_posX, float t_posY) : m_type(t_type)
{
	int xCoord = (int)t_posX - (int)t_posX % G_CELL_SIZE + G_CELL_SIZE / 2;
	int yCoord = (int)t_posY - (int)t_posY % G_CELL_SIZE + G_CELL_SIZE / 2;
	m_enemy.setOrigin(G_CELL_SIZE / 2, G_CELL_SIZE / 2);
	m_enemy.setPosition(sf::Vector2f(xCoord, yCoord));
	
	m_enemyTexture = TextureManager::Acquire(ITEMS_TEXTURE);

	m_enemy.setTexture(*m_enemyTexture);

	if (m_rects.size() == 0)
	{
		m_rects.try_emplace(EnemyType::Bat, sf::IntRect{ 0,160,16,16 });
		m_rects.try_emplace(EnemyType::Rat, sf::IntRect{ 64,160,16,16 });
	}

	m_enemy.setTextureRect(m_rects.at(m_type));

	m_enemy.setOrigin(m_enemy.getTextureRect().width / 2.0f,
		m_enemy.getTextureRect().height / 2.0f);
	m_enemy.setScale(2.0f, 2.0f);

	CombatSystem::PushBackEnemyStats(&health, xp);
}

/// <summary>
/// Updates and moves the enemy after each Player turn.
/// </summary>
void Enemy::update()
{
	if (health > 0)
	{
		move();
	}
}

/// <summary>
/// Moves the enemy around the Grid, one Tile per turn.
/// </summary>
void Enemy::move()
{
	sf::Vector2f pos = m_enemy.getPosition();
	int direction = rand() % 4;
	switch (direction)
	{
	case 0:
		pos.y -= G_CELL_SIZE;
		break;
	case 1:
		pos.x += G_CELL_SIZE;
		break;
	case 2:
		pos.y += G_CELL_SIZE;
		break;
	case 3:
		pos.x -= G_CELL_SIZE;
		break;
	}

	// if player isnt in next cell
	//m_enemy.setPosition(pos);

	//else
	CalculateDamageToPlayer(1);
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
