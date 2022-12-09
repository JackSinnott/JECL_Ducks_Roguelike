#include "CombatSystem.h"

std::vector<std::pair<int*, int>> CombatSystem::enemiesStats = std::vector<std::pair<int*, int>>();
int* CombatSystem::playerHealth = nullptr;

/// <summary>
/// 
/// </summary>
/// <param name="t_health"></param>
void CombatSystem::SetPlayerHealth(int* t_health)
{
	playerHealth = t_health;
}

/// <summary>
/// 
/// </summary>
/// <param name="t_health"></param>
void CombatSystem::PushBackEnemyStats(int* t_health, int t_xp)
{
	enemiesStats.push_back(std::make_pair(t_health, t_xp));
}

/// <summary>
/// 
/// </summary>
/// <param name="defendersArmour"></param>
/// <param name="attackersLevel"></param>
/// <param name="t_modifiers"></param>
/// <returns></returns>
bool CombatSystem::BattleEquation(int defendersArmour, int attackersLevel, int t_modifiers)
{
	int attackersRoll = CombatSystem::RollD20();
	attackersRoll++;
	attackersRoll += t_modifiers;

	int defendersRoll = 20 - attackersLevel - defendersArmour;

	return attackersRoll >= defendersRoll;
}

/// <summary>
/// 
/// </summary>
/// <param name="damage"></param>
void CombatSystem::HurtPlayer(int damage)
{
	(*playerHealth) -= damage;
	std::cout << "It did " << damage << " damage to you." << std::endl;
}

/// <summary>
/// 
/// </summary>
/// <param name="t_indexOfEnemy">The index of the enemies health in the vector</param>
/// <param name="damage">How much damage will be done to the enemy</param>
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
/// Returns a random number between 1 and 20
/// </summary>
/// <param name="amountRolled">The amount of times that dice should be rolled</param>
/// <returns>the resulting roll</returns>
int CombatSystem::RollD20(int amountRolled)
{
	int roll = 0;

	for (int i = 0; i < amountRolled; i++)
	{
		roll += (rand() % 20) + 1;
	}
	
	return roll;
}

int CombatSystem::RollD8(int amountRolled)
{
	int roll = 0;

	for (int i = 0; i < amountRolled; i++)
	{
		roll += (rand() % 8) + 1;
	}

	return roll;
}
