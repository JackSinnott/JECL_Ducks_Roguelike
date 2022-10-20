#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(std::string imageName = "MissingTexture.png", sf::Vector2f defaultPosition = {2, 2}, int t_rarity = 1);
	~Weapon();
	void setPosition();
private:
	int m_damage;
};

