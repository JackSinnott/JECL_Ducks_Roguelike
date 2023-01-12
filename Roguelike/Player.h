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
/// The class the user directly controls.
/// </summary>

class Player
{
private:
	///The field of view of the player.
	sf::View m_playerView;

	//sf::Sprite m_playerBody; 

	///Whether the Player is able to move right this turn.
	bool m_freeToMoveRight = true;

	///Whether the Player is able to move left this turn.
	bool m_freeToMoveLeft = true;

	///Whether the Player is able to move up this turn.
	bool m_freeToMoveUp = true;

	///Whether the Player is able to move down this turn.
	bool m_freeToMoveDown = true;
	
	///The Player's position last turn.
	sf::Vector2i m_previousPos;

	///The row the player is in on the Grid.
	int row;

	///The column the player is in on the Grid.
	int col;

	/// Appearance of player.
	sf::Sprite m_playerBody;

	///Reference to the texture of the player.
	std::shared_ptr<sf::Texture> m_playerTexture;

	/// <summary>
	/// The appearance of the player on the spritesheet, depending on the armours they can have.
	/// </summary>
	static std::unordered_map<Armours, sf::IntRect> m_rects;

	/// <summary>
	/// The appearance of the player on the spritesheet, if they are wearing no armour.
	/// </summary>
	static sf::IntRect m_noArmourRect;

	///The Player's inventory. This is where their items are stored.
	Inventory m_playerInventory;
	AbstractItem * m_starterWeapon;

	/// <summary>
	/// Keeps track of whether the player is currently pressing a button.
	/// </summary>
	sf::Keyboard::Key m_pressingButton = sf::Keyboard::Unknown;

	///The strength of the player, used for attacking.
	int m_strength = 10; 
	///The defense of the player, used for defending
	int m_armourClass = 2;
	///The health of the player. if this reaches 0, the game is over.
	int m_health = 20; 
	///The players level. as level increases, so does the health, strength, and defense.
	int level = 1; 
	///the players xp. When this reaches a certain threshold, level goes up by 1. XP is gotten by defeating enemies.
	int xp = 0; 

	///The current maximum health the player can have.
	int m_maxHealth = 20;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
	// Methods / Functions

	void UpdateArmourLook();

	// Combat Methods
	void CalculateDamageToEnemy(int t_EnemyAC, int t_index);
	int GetHitModifier();
	int GetDamageModifier();

public:

	Player();
	Player(int t_row, int t_col, AbstractItem* t_starterWeapon);

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
	
	/// <summary>
	/// Returns whether the Player can move up.
	/// </summary>
	/// <returns>Can the player move up?</returns>
	inline bool canWeMoveUp() { return m_freeToMoveUp; }

	/// <summary>
	/// Changes whether the Player can move up or not.
	/// </summary>
	/// <param name="t_switch">Change to if the player can move up.</param>
	inline void setMovementBoolUp(bool t_switch) { m_freeToMoveUp = t_switch; }

	/// <summary>
	/// Changes whether the Player can move down or not.
	/// </summary>
	/// <param name="t_switch">Change to if the player can move down.</param>
	inline void setMovementBoolDown(bool t_switch) { m_freeToMoveDown = t_switch; }

	/// <summary>
	/// Returns whether the Player can move down.
	/// </summary>
	/// <returns>Can the player move down?</returns>
	inline bool canWeMoveDown() { return m_freeToMoveDown; }

	/// <summary>
	/// Changes whether the Player can move left or not.
	/// </summary>
	/// <param name="t_switch">Change to if the player can move left.</param>
	inline void setMovementBoolLeft(bool t_switch) { m_freeToMoveLeft = t_switch; }

	/// <summary>
	/// Returns whether the Player can move left.
	/// </summary>
	/// <returns>Can the player move left?</returns>
	inline bool canWeMoveLeft() { return m_freeToMoveLeft; }

	/// <summary>
	/// Changes whether the Player can move right or not.
	/// </summary>
	/// <param name="t_switch">Change to if the player can move right.</param>
	inline void setMovementBoolRight(bool t_switch) { m_freeToMoveRight = t_switch;	}

	/// <summary>
	/// Returns whether the Player can move right.
	/// </summary>
	/// <returns>Can the player move right?</returns>
	inline bool canWeMoveRight() { return m_freeToMoveRight; }

	inline void resetMovementBools(bool t_switch) { setMovementBoolUp(t_switch); setMovementBoolDown(t_switch);
		setMovementBoolLeft(t_switch); setMovementBoolRight(t_switch); }

	// Inventory Methods

	void PickUpItem(AbstractItem& t_item);
	int GetWeaponDamage();
	int GetArmourClass();
	void UsePotion();
};