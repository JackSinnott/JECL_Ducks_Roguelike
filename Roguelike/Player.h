#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>
#include "AbstractItem.h"
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"

#include "CombatSystem.h"

/// <summary>
/// Class the player directly controls.
/// </summary>

class Player
{
private:

	// Variables

	/// Appearance of player.
	/// For now it will be a rectangle shape, until a spritesheet can be sorted.
	sf::Sprite m_playerBody;

	/// Reference to the texture of the player.
	std::shared_ptr<sf::Texture> m_playerTexture;
	static std::unordered_map<Armours, sf::IntRect> m_rects;
	static sf::IntRect m_noArmourRect;

	//A basic inventory
	Weapons m_playerWeapon;

	AbstractWeapon * m_currentWeapon;
	AbstractArmour * m_currentArmour;
	AbstractPotion * m_currentPotion;

	/// <summary>
	/// Keeps track of whether the player is currently pressing a button.
	/// </summary>
	sf::Keyboard::Key m_pressingButton = sf::Keyboard::Unknown;

	int m_strength = 10; // The strength of the player, used for attacking
	int m_armourClass = 2; // The defense of the player, used for defending
	int health = 20; // The health of the player. if this reaches 0, the game is over.
	int level = 1; // The players level. as level increases, so does the health, strength, and defense.
	int xp = 0; // the players xp. When this reaches a certain threshold, level goes up by 1. XP is gotten by defeating enemies.

	// Methods / Functions

	void UpdateArmourLook();

	// Combat Methods
	void CalculateDamageToEnemy(int t_EnemyAC, int t_index);
	int GetHitModifier();
	int GetDamageModifier();

public:

	Player();
	void move(int row, int col);

	// The three main processes

	void Update(sf::Time t_deltaTime);
	bool ProcessKeys(sf::Event t_event);
	void Render(sf::RenderWindow& t_window);

	// get / sets

	sf::Vector2f GetPosition();
	void setPosition(int row, int col);

	// Inventory Methods

	void PickUpItem(AbstractItem& t_item);
	int GetWeaponDamage();
	int GetArmourClass();
	void UsePotion();
};