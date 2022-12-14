#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "TextureManager.h"


/// <summary>
/// Abstract item that all items derive from
/// </summary>
class AbstractItem
{
public:
	~AbstractItem() { delete this; };

	/// <summary>
	/// Draw method for drawing the item's sprite
	/// </summary>
	/// <param name="t_window"></param>
	void draw(sf::RenderWindow& t_window) { t_window.draw(m_itemSprite); };


	/// <summary>
	/// Generates a random positon on the grid for said item
	/// </summary>
	void GenerateRandomPosition()
	{
		int randomeX = rand() % 56 + 16;
		int randomeY = rand() % 28 + 16;

		m_itemSprite.setPosition( sf::Vector2f(randomeX, randomeY) * float(G_CELL_SIZE));
	}

	/// <summary>
	/// Sets a positon on the grid for said item from a vector
	/// </summary>
	void SetRandomPosition(sf::Vector2f t_v)
	{
		m_itemSprite.setPosition((t_v + sf::Vector2f(16,16)) + sf::Vector2f(32,32) * 5.0f);
		//m_itemSprite.setPosition(t_v);
	}

	/// <summary>
	/// Sets up the item's texture, a generic position and scale of the sprite
	/// </summary>
	void SetupBasics()
	{
		m_itemTexture = TextureManager::Acquire(ITEMS_TEXTURE);
		m_itemSprite.setTexture(*m_itemTexture);
		m_itemSprite.setOrigin(m_itemSprite.getTextureRect().width/ 2.0f, m_itemSprite.getTextureRect().height / 2.0f);

		//m_itemSprite.setPosition(G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f,
		//	G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f);
		m_itemSprite.setScale(2.0f, 2.0f);
	}


	/// <summary>
	/// Gets the type of the item
	/// </summary>
	/// <returns>Type of the item</returns>
	ItemType GetItemType()
	{
		return m_itemType;
	}


	/// <summary>
	/// Returns a reference to the item's sprite
	/// </summary>
	/// <returns></returns>
	sf::Sprite & GetSprite()
	{
		return m_itemSprite;
	}

protected:
	int m_rarity = 0; //Item rarity, affects it's stats
	std::shared_ptr<sf::Texture> m_itemTexture; // Shared pointer to the texture
	sf::Sprite m_itemSprite;//The item's sprite
	ItemType m_itemType;//The type of item it is
};