#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"
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
	Weapons m_weaponType;
	std::shared_ptr<sf::Texture> m_pTexture;
	int m_rarity;
};

