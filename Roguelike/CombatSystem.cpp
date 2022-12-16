#include "CombatSystem.h"

std::vector<std::pair<int*, int>> CombatSystem::enemiesStats = std::vector<std::pair<int*, int>>();
int* CombatSystem::playerHealth = nullptr;

/// <summary>
/// Lets the system be able to affect the Player's health.
/// </summary>
/// <param name="t_health">The reference to the Player's health.</param>
void CombatSystem::SetPlayerHealth(int* t_health)
{
	playerHealth = t_health;
}

/// <summary>
/// Pushes back some enemy stats, so the combat will be able to affect the enemies.
/// </summary>
/// <param name="t_health">A reference to the health of an enemy.</param>
/// <param name="t_xp">A copy of the xp the enemy will drop when they are defeated.</param>
void CombatSystem::PushBackEnemyStats(int* t_health, int t_xp)
{
	enemiesStats.push_back(std::make_pair(t_health, t_xp));
}

/// <summary>
/// Calculates whether the attacker hits the defender.
/// </summary>
/// <param name="defendersArmour">How hard it is to hit the defender.</param>
/// <param name="attackersLevel">The level the attacker is at - this affects their hit chance.</param>
/// <param name="t_modifiers">Hit chance modifiers, which is added after the roll.</param>
/// <returns>Whether the hit went through.</returns>
bool CombatSystem::BattleEquation(int defendersArmour, int attackersLevel, int t_modifiers)
{
	int attackersRoll = CombatSystem::RollD20();
	attackersRoll++;
	attackersRoll += t_modifiers;

	int defendersRoll = 20 - attackersLevel - defendersArmour;

	return attackersRoll >= defendersRoll;
}

/// <summary>
/// Deal some damage to the Player.
/// </summary>
/// <param name="damage">The amount of damage to do to the Player.</param>
void CombatSystem::HurtPlayer(int damage)
{
	(*playerHealth) -= damage;
	std::cout << "It did " << damage << " damage to you." << std::endl;
}

/// <summary>
/// Deals some damage to a specified Enemy. If the enemy is defeated, remove them from the vector.
/// </summary>
/// <param name="t_indexOfEnemy">The index of the Enemy in the vector.</param>
/// <param name="damage">How much damage will be done to the Enemy.</param>
int CombatSystem::HurtEnemy(int t_indexOfEnemy, int damage)
{
	int xpGotten = 0;

	if (enemiesStats.size() > t_indexOfEnemy)
	{
		(*enemiesStats[t_indexOfEnemy].first) -= damage;
		std::cout << "You did " << damage << " damage." << std::endl;

		if ((*enemiesStats[t_indexOfEnemy].first) <= 0)
		{
			xpGotten = enemiesStats[t_indexOfEnemy].second;
			enemiesStats.erase(enemiesStats.begin() + t_indexOfEnemy);
		}
	}

	return xpGotten;
}

/// <summary>
/// Returns a random number between 1 and 20 (inclusive), adds them together if the amount rolled is more than 1, then returns the result.
/// </summary>
/// <param name="amountRolled">The amount of times that dice should be rolled.</param>
/// <returns>The resulting roll of all the dice,
/// ie. if the dice is rolled twice and got 10 and 16, 26 is returned.</returns>
int CombatSystem::RollD20(int amountRolled)
{
	int roll = 0;

	for (int i = 0; i < amountRolled; i++)
	{
		roll += (rand() % 20) + 1;
	}
	
	return roll;
}

/// <summary>
/// Generates a number between 1 and 8 (inclusive), adds them together if the amount rolled is more than 1, then returns the result.
/// </summary>
/// <param name="amountRolled">The amount of times the dice is rolled.</param>
/// <returns>The resulting roll of all the dice,
/// ie. if the dice is rolled twice and got 2 and 3, 5 is returned.</returns>
int CombatSystem::RollD8(int amountRolled)
{
	int roll = 0;

	for (int i = 0; i < amountRolled; i++)
	{
		roll += (rand() % 8) + 1;
	}

	return roll;
}
