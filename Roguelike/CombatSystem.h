#pragma once
#include <vector>
#include <iostream>

class CombatSystem
{
private:

	/// <summary>
	/// Reference to all the enemies' healths,
	/// and how much xp they would give the player when they're defeated.
	/// </summary>
	static std::vector<std::pair<int*, int>> enemiesStats;

	static int* playerHealth; // Reference to the player's health.

	static int RollD20(int amountRolled = 1);

public:
	static int RollD8(int amountRolled = 1);

	static void PushBackEnemyStats(int* t_health, int t_xp);

	static bool BattleEquation(int defendersArmour, int attackersLevel = 0, int t_modifiers = 0);

	static void HurtPlayer(int damage);
	static int HurtEnemy(int t_indexOfEnemy, int damage);
};

