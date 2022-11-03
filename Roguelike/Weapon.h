#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(Weapons t_weaponType,std::string t_imageName = "MissingTexture.png", sf::Vector2f t_defaultPosition = {2, 2}, int t_rarity = 1);
	~Weapon();
	int getDamage();
private:
	int m_damage = 1;

};

