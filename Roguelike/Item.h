#pragma once
#include <SFML/Graphics.hpp>
class Item
{
public:

	Item();
	~Item();
private:
	std::string m_name;
	sf::Vector2f m_position;
	sf::Sprite m_itemSprite;
	sf::Sprite m_itemTexture;
	int m_rarity;

};

