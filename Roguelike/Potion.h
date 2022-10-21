#pragma once
#include "Item.h"
class Potion : public Item
{
public:
	Potion(std::string imageName = "MissingTexture.png", sf::Vector2f defaultPosition = { 2, 2 }, int t_rarity = 1);
	~Potion();
private:
	int m_healAmount;
	int m_strengthDamageMod;
	int m_speedAmount;
};

