#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>
#include "AbstractItem.h"
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"

/// <summary>
/// Class the player directly controls.
/// </summary>

class Player
{
private:

	// Variables

	//sf::Sprite m_playerBody; 

	int m_x, m_y;
	/// Appearance of player.
	/// For now it will be a rectangle shape, until a spritesheet can be sorted.
	sf::RectangleShape m_playerBody;

	/// Reference to the texture of the player.
	sf::Texture* m_playerTexture;


	//A basic inventory
	Weapons m_playerWeapon;

	//AbstractWeapon m_testingWeapon;

	AbstractItem * m_currentWeapon;
	AbstractItem * m_currentArmour;
	AbstractItem * m_currentPotion;

	/// <summary>
	/// Keeps track of whether the player is currently pressing a button.
	/// </summary>
	sf::Keyboard::Key m_pressingButton = sf::Keyboard::Unknown;

	/// <summary>
	/// Temporary variable - Used for moving between grid cells.
	/// Will be replaced once Grid class is set up.
	/// </summary>
	float gridCellSize = 50.0f;

	int m_damage = 2;
	int m_armourClass = 2;
	int health = 20;
	int level = 1;
	int xp = 0;
	// Methods / Functions

	//void MoveSquare(sf::Vector2f t_direction);

public:

	//void InitialiseTextures();

	void move(int row, int col);

	Player();

	void Update(sf::Time t_deltaTime);
	bool ProcessKeys(sf::Event t_event);
	void Render(sf::RenderWindow& t_window);

	sf::Vector2f GetPosition();
	void setPosition(int row, int col);
	void PickUpItem(AbstractItem& t_item);
	int GetWeaponDamage();
	int GetArmourClass();
	void UsePotion();
};