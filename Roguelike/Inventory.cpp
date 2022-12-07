#include "Inventory.h"

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

Inventory::~Inventory()
{

}

void Inventory::SetupInventory(sf::Vector2f t_playerPosition)
{
	m_inventoryBackground.setPosition(t_playerPosition.x - 440, t_playerPosition.y);
	m_inventoryBlockWeapon.setPosition(t_playerPosition.x - 440, t_playerPosition.y + 50 );
	//m_inventoryBackground.setPosition(t_playerPosition);
	
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

void Inventory::Draw(sf::RenderWindow& t_window)
{
	if (m_showInventory)
	{
		//Draws all inventory related sprites and objects
		t_window.draw(m_inventoryBackground);
		t_window.draw(m_inventoryBlockWeapon);
		t_window.draw(m_inventoryBlockArmour);
		t_window.draw(m_inventoryBlockPotion);
		t_window.draw(m_inventoryWeaponSprite);
		t_window.draw(m_inventoryArmourSprite);
		t_window.draw(m_inventoryPotionSprite);
	}
}

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

void Inventory::RemovePotion()
{
	m_currentPotion = nullptr;
}

AbstractWeapon& Inventory::GetWeapon()
{
	return * m_currentWeapon;
}

AbstractArmour& Inventory::GetArmour()
{
	return * m_currentArmour;
}

AbstractPotion& Inventory::GetPotion()
{
	return * m_currentPotion;
}
