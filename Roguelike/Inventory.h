#pragma once
#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>
#include "AbstractItem.h"
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"
#include "AxeWeapon.h"
class Inventory
{
public:
	Inventory();
	~Inventory();
	void SetupInventory(sf::Vector2f t_playerPosition);

	void StoreItem(AbstractItem& t_item);
	void UpdatePosition(sf::Vector2f t_playerPosition);
	void Draw(sf::RenderWindow& t_window);
	void ToggleInventory();
	void RemovePotion();
	//Getting an item
	AbstractWeapon& GetWeapon();
	AbstractArmour& GetArmour();
	AbstractPotion& GetPotion();

private:
	AbstractWeapon* m_currentWeapon; //Stores the current weapon the player has.
	AbstractArmour* m_currentArmour; //Stores the current armour the player has.
	AbstractPotion* m_currentPotion; //Stores the current potion the player has.

	sf::RectangleShape m_inventoryBackground;  //Background that shows the player's inventory.
	sf::RectangleShape m_inventoryBlockWeapon; //Block to show the specific item the player has.
	sf::RectangleShape m_inventoryBlockArmour; //Block to show the specific item the player has.
	sf::RectangleShape m_inventoryBlockPotion; //Block to show the specific item the player has.

	sf::Sprite m_inventoryWeaponSprite;//Sprite of the current item the player has.
	sf::Sprite m_inventoryArmourSprite;//Sprite of the current item the player has.
	sf::Sprite m_inventoryPotionSprite;//Sprite of the current item the player has.

	sf::Vector2f m_cellOffset;

	bool m_showInventory;
};

