#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "TextureManager.h"

class AbstractItem
{
public:
	~AbstractItem() { delete this; };
	void draw(sf::RenderWindow& t_window) { t_window.draw(m_itemSprite); };
	void GenerateRandomPosition()
	{
		int randomeX = rand() % 20 + 3;
		int randomeY = rand() % 20 + 3;

		m_itemSprite.setPosition( sf::Vector2f(randomeX, randomeY) * float(G_CELL_SIZE));
	}

	void SetupBasics()
	{
		m_itemTexture = TextureManager::Acquire(ITEMS_TEXTURE);
		m_itemSprite.setTexture(*m_itemTexture);
		m_itemSprite.setOrigin(m_itemSprite.getTextureRect().width/ 2.0f, m_itemSprite.getTextureRect().height / 2.0f);

		m_itemSprite.setPosition(G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f,
			G_CELL_SIZE * (10) + G_CELL_SIZE / 2.0f);
		m_itemSprite.setScale(2.0f, 2.0f);
	}

	ItemType GetItemType()
	{
		return m_itemType;
	}
protected:
	int m_rarity = 0;
	std::shared_ptr<sf::Texture> m_itemTexture;
	sf::Sprite m_itemSprite;
	ItemType m_itemType;
};