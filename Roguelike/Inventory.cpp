#include "Inventory.h"

/// <summary>
/// Default constructor, used to create the inventory.
/// </summary>
Inventory::Inventory()
{
	m_showInventory = false;
	m_inventoryBackground.setFillColor(sf::Color(250, 219, 162));
	m_inventoryBackground.setSize(sf::Vector2f(128, 192));
	m_inventoryBackground.setOrigin(m_inventoryBackground.getSize()/2.0f);

	m_inventoryBlockWeapon.setFillColor(sf::Color::Red);
	m_inventoryBlockWeapon.setSize(sf::Vector2f(64, 64));
	m_inventoryBlockWeapon.setOrigin(m_inventoryBlockWeapon.getSize() / 2.0f);

	m_inventoryBlockArmour.setFillColor(sf::Color::Blue);
	m_inventoryBlockArmour.setSize(sf::Vector2f(64, 64));
	m_inventoryBlockArmour.setOrigin(m_inventoryBlockArmour.getSize() / 2.0f);

	m_inventoryBlockPotion.setFillColor(sf::Color::Green);
	m_inventoryBlockPotion.setSize(sf::Vector2f(64, 64));
	m_inventoryBlockPotion.setOrigin(m_inventoryBlockPotion.getSize() / 2.0f);

	m_cellOffset = sf::Vector2f(G_CELL_SIZE * (5) + G_CELL_SIZE / 2.0f, G_CELL_SIZE * (5) + G_CELL_SIZE / 2.0f);
}

/// <summary>
/// Default deconstructor.
/// </summary>
Inventory::~Inventory()
{

}

/// <summary>
/// Sets up the inventory sprites and positions depending on if the player has items in their inventory.
/// </summary>
/// <param name="t_playerPosition">The Player's position on the grid.</param>
void Inventory::SetupInventory(sf::Vector2f t_playerPosition)
{
	m_inventoryBackground.setPosition(t_playerPosition.x - 385, t_playerPosition.y);

	m_inventoryBlockWeapon.setPosition(m_inventoryBackground.getPosition().x, m_inventoryBackground.getPosition().y - 64);
	m_inventoryBlockArmour.setPosition(m_inventoryBackground.getPosition().x, m_inventoryBackground.getPosition().y);
	m_inventoryBlockPotion.setPosition(m_inventoryBackground.getPosition().x, m_inventoryBackground.getPosition().y + 64);
	
	if (m_currentWeapon != nullptr)
	{
		m_inventoryWeaponSprite.setPosition(m_inventoryBackground.getPosition());
	}	
	if (m_currentArmour != nullptr)
	{
		m_inventoryArmourSprite.setPosition(m_inventoryBackground.getPosition());
	}	
	if (m_currentPotion != nullptr)
	{
		m_inventoryPotionSprite.setPosition(m_inventoryBackground.getPosition());
	}
}


/// <summary>
/// Stores the current item the player picked up.
/// </summary>
/// <param name="t_item">The new picked up item.</param>
void Inventory::StoreItem(AbstractItem& t_item)
{
	switch (t_item.GetItemType())
	{
	case ItemType::Weapon:
		m_currentWeapon = static_cast<AbstractWeapon*>(&t_item);
		m_inventoryWeaponSprite = m_currentWeapon->GetSprite();
		std::cout << "You picked up a weapon" << std::endl;
		break;
	case ItemType::Armour:
		m_currentArmour = static_cast<AbstractArmour*>(&t_item);
		m_inventoryArmourSprite = m_currentArmour->GetSprite();
		std::cout << "You picked up some armour" << std::endl;
		break;
	case ItemType::Potion:
		m_currentPotion = static_cast<AbstractPotion*>(&t_item);;
		m_inventoryPotionSprite = m_currentPotion->GetSprite();
		std::cout << "You picked up a potion" << std::endl;
		break;
	default:
		std::cout << "Unable to get item type" << std::endl;
		break;
	}
}

/// <summary>
/// Updates the position of the inventory, to match where the player is.
/// </summary>
/// <param name="t_playerPosition">The Player's position on the grid.</param>
void Inventory::UpdatePosition(sf::Vector2f t_playerPosition)
{
	//m_inventoryBackground.setPosition(t_playerPosition.x - 440, t_playerPosition.y - 100);
	m_inventoryBackground.setPosition(t_playerPosition.x - 385, t_playerPosition.y);

	m_inventoryBlockWeapon.setPosition(m_inventoryBackground.getPosition().x, m_inventoryBackground.getPosition().y -64);
	m_inventoryBlockArmour.setPosition(m_inventoryBackground.getPosition().x, m_inventoryBackground.getPosition().y);
	m_inventoryBlockPotion.setPosition(m_inventoryBackground.getPosition().x, m_inventoryBackground.getPosition().y + 64);

	if (m_currentWeapon != nullptr)
	{
		m_inventoryWeaponSprite.setPosition(m_inventoryBlockWeapon.getPosition() + m_cellOffset);
	}
	if (m_currentArmour != nullptr)
	{
		m_inventoryArmourSprite.setPosition(m_inventoryBlockArmour.getPosition() + m_cellOffset);
	}
	if (m_currentPotion != nullptr)
	{
		m_inventoryPotionSprite.setPosition(m_inventoryBlockPotion.getPosition() + m_cellOffset);
	}

	std::cout << "------------------" << std::endl;
}

/// <summary>
/// Draws all sprites, depending on if the player has items in their inventory.
/// </summary>
/// <param name="t_window">The window to draw to.</param>
void Inventory::Draw(sf::RenderWindow& t_window)
{
	if (m_showInventory)
	{
		//Draws all inventory related sprites and objects
		t_window.draw(m_inventoryBackground);
		t_window.draw(m_inventoryBlockWeapon);
		t_window.draw(m_inventoryBlockArmour);
		t_window.draw(m_inventoryBlockPotion);
		if (m_currentWeapon != nullptr)
		{
			t_window.draw(m_inventoryWeaponSprite);
		}
		if (m_currentArmour != nullptr)
		{
			t_window.draw(m_inventoryArmourSprite);
		}
		if (m_currentPotion != nullptr)
		{
			t_window.draw(m_inventoryPotionSprite);
		}
	}
}


/// <summary>
/// A simple toggle to show or hide the player's inventory.
/// </summary>
void Inventory::ToggleInventory()
{
	m_showInventory = !m_showInventory;

	if (m_showInventory)
	{
		std::cout <<"Inventory is shown"<< std::endl;
	}
	else
	{
		std::cout << "Inventory is not shown" << std::endl;
	}
}

/// <summary>
/// Once the potion is used up, it is removed from the player's inventory.
/// </summary>
void Inventory::RemovePotion()
{
	m_currentPotion = nullptr;
}


/// <summary>
/// Gets a reference to the current player's weapon.
/// </summary>
/// <returns>The Player's weapon.</returns>
AbstractWeapon& Inventory::GetWeapon()
{
	return * m_currentWeapon;
}


/// <summary>
/// Gets a reference to the current player's armour.
/// </summary>
/// <returns>The Player's armour.</returns>
AbstractArmour& Inventory::GetArmour()
{
	return * m_currentArmour;
}

/// <summary>
/// Gets a reference to the current player's potion
/// </summary>
/// <returns>The Player's potion.</returns>
AbstractPotion& Inventory::GetPotion()
{
	return * m_currentPotion;
}
