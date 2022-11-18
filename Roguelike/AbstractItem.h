#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "TextureManager.h"

class AbstractItem
{
public:
	~AbstractItem() {};
	void draw(sf::RenderWindow& t_window) { t_window.draw(m_itemSprite); };
	void GenerateRandomPosition()
	{
		int randomeX = rand() % 20 + 3;
		int randomeY = rand() % 20 + 3;

		m_itemSprite.setPosition( sf::Vector2f(randomeX, randomeY) * float(G_CELL_SIZE));
	};
protected:
	int m_rarity = 0;
	std::shared_ptr<sf::Texture> m_itemTexture;
	sf::Sprite m_itemSprite;
};