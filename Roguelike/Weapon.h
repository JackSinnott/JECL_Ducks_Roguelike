#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon();
	Weapon(std::string t_imageName = "MissingTexture.png", sf::Vector2f t_defaultPosition = {2, 2}, int t_rarity = 1);
	~Weapon();
	void setup(std::string imageName, sf::Vector2f defaultPosition, int t_rarity);
private:
	int m_damage;

};

