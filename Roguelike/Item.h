#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
class Item
{
public:

	Item(std::string t_itemImageName, sf::Vector2f t_position, int t_rarity);
	~Item();
	void draw(sf::RenderWindow& t_window);
protected:
	std::string m_name;
	sf::Vector2f m_position;
	sf::Sprite m_itemSprite;
	sf::Texture m_itemTexture;
	int m_rarity;
};

