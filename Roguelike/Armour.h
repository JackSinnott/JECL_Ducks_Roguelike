#pragma once
#include "Item.h"
class Armour : public Item
{
public:
	Armour(std::string imageName = "MissingTexture.png", sf::Vector2f defaultPosition = { 2, 2 }, int t_rarity = 1);
	~Armour();
	int getArmourRating();
private:
	int m_armourRating;

};

