#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>
#include "AbstractItem.h"
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"
#include "Inventory.h"
/// <summary>
/// Class the player directly controls.
/// </summary>

class Player
{
private:
	//Field of view of the player
	sf::View m_playerView;

	// Variables
		
	//sf::Sprite m_playerBody; 

	int m_x, m_y;
	/// Appearance of player.
	/// For now it will be a rectangle shape, until a spritesheet can be sorted.
	sf::Sprite m_playerBody;

	/// Reference to the texture of the player.
	std::shared_ptr<sf::Texture> m_playerTexture;
	static std::unordered_map<Armours, sf::IntRect> m_rects;
	static sf::IntRect m_noArmourRect;

	//A basic inventory

	//AbstractWeapon * m_currentWeapon;
	//AbstractArmour * m_currentArmour;
	//AbstractPotion * m_currentPotion;

	Inventory m_playerInventory;

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
	int m_health = 20;
	int m_maxHealth = 20; //Current maximum health the player can have
	int m_level = 1;
	int xp = 0;
	// Methods / Functions

	//void MoveSquare(sf::Vector2f t_direction);

	void UpdateArmourLook();

public:

	//void InitialiseTextures();

	void move(int row, int col);

	Player();

	void Update(sf::Time t_deltaTime);
	bool ProcessKeys(sf::Event t_event);
	void Render(sf::RenderWindow& t_window);

	//sf::Vector2f GetPosition();
	void setGridPosition(int row, int col);
	void PickUpItem(AbstractItem& t_item);
	int GetWeaponDamage();
	int GetArmourClass();
	void UsePotion();
};