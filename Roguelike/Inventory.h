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
	AbstractWeapon* m_currentWeapon;
	AbstractArmour* m_currentArmour;
	AbstractPotion* m_currentPotion;

	sf::RectangleShape m_inventoryBackground;
	//sf::RectangleShape m_inventoryBlockWeapon;
	//sf::RectangleShape m_inventoryBlockArmour;
	//sf::RectangleShape m_inventoryBlockPotion;

	sf::Sprite m_inventoryWeaponSprite;
	sf::Sprite m_inventoryArmourSprite;
	sf::Sprite m_inventoryPotionSprite;

	bool m_showInventory;
};

