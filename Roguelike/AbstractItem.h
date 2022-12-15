#pragma once
#include "Globals.h"
#include "TextureManager.h"


/// <summary>
/// Abstract item that all in-game items derive from.
/// This includes all the AbstractWeapon, AbstractArmour, and AbstractPotion.
/// </summary>
class AbstractItem
{
public:
	
	/// <summary>
	/// Class's Default Deconstructor.
	/// </summary>
	~AbstractItem() { delete this; };

	/// <summary>
	/// Draw method for drawing the item's sprite.
	/// </summary>
	/// <param name="t_window">The window to the item to.</param>
	void draw(sf::RenderWindow& t_window) { t_window.draw(m_itemSprite); };


	/// <summary>
	/// Generates a random positon on the grid for said item.
	/// </summary>
	void GenerateRandomPosition()
	{
		int randomeX = rand() % 56 + 16;
		int randomeY = rand() % 28 + 16;

		m_itemSprite.setPosition( sf::Vector2f(randomeX, randomeY) * float(G_CELL_SIZE));
	}


	/// <summary>
	/// Sets up the item's texture, a generic position and scale of the sprite.
	/// </summary>
	void SetupBasics()
	{
		m_itemTexture = TextureManager::Acquire(ITEMS_TEXTURE);
		m_itemSprite.setTexture(*m_itemTexture);
		m_itemSprite.setOrigin(m_itemSprite.getTextureRect().width/ 2.0f, m_itemSprite.getTextureRect().height / 2.0f);

		m_itemSprite.setPosition(G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f,
			G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f);
		m_itemSprite.setScale(2.0f, 2.0f);
	}


	/// <summary>
	/// Gets the type of the item.
	/// </summary>
	/// <returns>Type of the item.</returns>
	ItemType GetItemType()
	{
		return m_itemType;
	}


	/// <summary>
	/// Returns a reference to the item's sprite.
	/// </summary>
	/// <returns>The item's sprite.</returns>
	sf::Sprite & GetSprite()
	{
		return m_itemSprite;
	}

protected:
	///Item rarity, affects it's stats.
	int m_rarity = 0;

	///Shared pointer to the texture.
	std::shared_ptr<sf::Texture> m_itemTexture;

	///The item's sprite.
	sf::Sprite m_itemSprite;

	///The type of item it is.
	ItemType m_itemType = ItemType::Weapon;
};