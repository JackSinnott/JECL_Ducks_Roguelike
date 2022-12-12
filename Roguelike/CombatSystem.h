#pragma once
#include <vector>
#include <iostream>

class CombatSystem
{
private:
	// static Ref to enemies' healths
	static std::vector<std::pair<int*, int>> enemiesStats;

	// static ref to player's health
	static int* playerHealth;

	static int RollD20(int amountRolled = 1);

public:
	static int RollD8(int amountRolled = 1);

	static void SetPlayerHealth(int* t_health);
	static void PushBackEnemyStats(int* t_health, int t_xp);

	static bool BattleEquation(int defendersArmour, int attackersLevel = 0, int t_modifiers = 0);

	static void HurtPlayer(int damage);
	static int HurtEnemy(int t_indexOfEnemy, int damage);
};

