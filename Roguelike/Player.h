#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "AbstractItem.h"
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"
#include "Inventory.h"
#include "CombatSystem.h"

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

	bool m_freeToMoveRight = true;
	bool m_freeToMoveLeft = true;
	bool m_freeToMoveUp = true;
	bool m_freeToMoveDown = true;
	

	sf::Vector2i m_previousPos;

	int m_x, m_y;

	int row, col;
	/// Appearance of player.
	/// For now it will be a rectangle shape, until a spritesheet can be sorted.
	sf::Sprite m_playerBody;

	/// Reference to the texture of the player.
	std::shared_ptr<sf::Texture> m_playerTexture;
	static std::unordered_map<Armours, sf::IntRect> m_rects;
	static sf::IntRect m_noArmourRect;

	//A basic inventory
	Inventory m_playerInventory;

	/// <summary>
	/// Keeps track of whether the player is currently pressing a button.
	/// </summary>
	sf::Keyboard::Key m_pressingButton = sf::Keyboard::Unknown;

	int m_strength = 10; // The strength of the player, used for attacking
	int m_armourClass = 2; // The defense of the player, used for defending
	int m_health = 20; // The health of the player. if this reaches 0, the game is over.
	int level = 1; // The players level. as level increases, so does the health, strength, and defense.
	int xp = 0; // the players xp. When this reaches a certain threshold, level goes up by 1. XP is gotten by defeating enemies.

	int m_maxHealth = 20; //Current maximum health the player can have
	// Methods / Functions

	void UpdateArmourLook();

	// Combat Methods
	void CalculateDamageToEnemy(int t_EnemyAC, int t_index);
	int GetHitModifier();
	int GetDamageModifier();

public:
	Player();
	Player(int t_row, int t_col);

	//void InitialiseTextures();

	inline sf::Vector2i getPreviousPos() { return m_previousPos; }

	inline void setPreviousPos(sf::Vector2i t_prev) { m_previousPos = t_prev; }

	void setPlayerPositionInGrid();
	void setPlayerPositionInGrid(sf::Vector2i t_pos);
	sf::Vector2i getPlayerPositionInGrid();

	void move(int row, int col);
	void reset();

	// The three main processes
	void Update(sf::Time t_deltaTime);
	bool ProcessKeys(sf::Event t_event);
	void Render(sf::RenderWindow& t_window);

	// get / sets

	sf::Vector2f GetPosition();
	void setGridPosition(int row, int col);
	
	inline bool canWeMoveUp() { return m_freeToMoveUp; }
	inline void setMovementBoolUp(bool t_switch) { m_freeToMoveUp = t_switch; }

	inline void setMovementBoolDown(bool t_switch) { m_freeToMoveDown = t_switch; }
	inline bool canWeMoveDown() { return m_freeToMoveDown; }

	inline void setMovementBoolLeft(bool t_switch) { m_freeToMoveLeft = t_switch; }
	inline bool canWeMoveLeft() { return m_freeToMoveLeft; }

	inline void setMovementBoolRight(bool t_switch) { m_freeToMoveRight = t_switch;	}
	inline bool canWeMoveRight() { return m_freeToMoveRight; }

	inline void resetMovementBools(bool t_switch) { setMovementBoolUp(t_switch); setMovementBoolDown(t_switch);
		setMovementBoolLeft(t_switch); setMovementBoolRight(t_switch); }

	// Inventory Methods

	void PickUpItem(AbstractItem& t_item);
	int GetWeaponDamage();
	int GetArmourClass();
	void UsePotion();
};