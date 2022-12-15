#pragma once
#include "Globals.h"
#include <unordered_map>
#include "TextureManager.h"

#include "CombatSystem.h"
#include <iostream>

/// <summary>
/// The enemies of the Player. Will try and hunt down and defeat them.
/// </summary>

class Enemy
{
public:
	Enemy(EnemyType t_type, float t_posX, float t_posY);

	void update();
	void move();
	void CalculateDamageToPlayer(int t_playerAC);
	void render(sf::RenderWindow& t_window);
	int GetArmourClass();
private:

	/// The armour class. The higher the number, the easier the enemy is to hit.
	int m_armourClass = 2;

	///The enemy's health. When this is reduced to 0, the enemy is defeated.
	int health = 20;

	///The amount of experience the enemy gives the player upon being defeated.
	int xp = 10;

	int GetDamage();

	///The type of enemy this is. These include #Bat and #Rat.
	const EnemyType m_type;

	///The appearance of the enemy.
	sf::Sprite m_enemy;

	///The spritesheet texture applied to the enemy appearance.
	std::shared_ptr<sf::Texture> m_enemyTexture;

	/// <summary>
	/// The rectangles needed to extract the right appearance from the spritesheet texture.
	/// </summary>
	static std::unordered_map<EnemyType, sf::IntRect> m_rects;
};
