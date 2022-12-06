#include "Inventory.h"

Inventory::Inventory()
{
	m_showInventory = false;
	m_inventoryBackground.setFillColor(sf::Color(250, 219, 162));
	m_inventoryBackground.setSize(sf::Vector2f(64, 192));
}

Inventory::~Inventory()
{

}

void Inventory::SetupInventory(sf::Vector2f t_playerPosition)
{
	m_inventoryBackground.setPosition(t_playerPosition.x - 440, t_playerPosition.y);
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
	m_inventoryBackground.setPosition(t_playerPosition.x - 440, t_playerPosition.y);

	if (m_currentWeapon != nullptr)
	{
		//m_currentWeapon->GetSprite().setPosition(m_inventoryBackground.getPosition());
		m_inventoryWeaponSprite.setPosition(m_inventoryBackground.getPosition());
		std::cout << m_inventoryWeaponSprite.getPosition().x << ", " << m_inventoryWeaponSprite.getPosition().y << std::endl;
	}
	if (m_currentArmour != nullptr)
	{
		m_inventoryArmourSprite.setPosition(m_inventoryBackground.getPosition());
		std::cout << m_inventoryArmourSprite.getPosition().x << ", " << m_inventoryArmourSprite.getPosition().y << std::endl;

	}
	if (m_currentPotion != nullptr)
	{
		m_inventoryPotionSprite.setPosition(m_inventoryBackground.getPosition());
		std::cout << m_inventoryPotionSprite.getPosition().x << ", " << m_inventoryPotionSprite.getPosition().y << std::endl;

	}

	std::cout << "------------------" << std::endl;
}

void Inventory::Draw(sf::RenderWindow& t_window)
{
	if (m_showInventory)
	{
		t_window.draw(m_inventoryBackground);
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
