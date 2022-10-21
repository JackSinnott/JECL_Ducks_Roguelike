#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(std::string t_imageName = "MissingTexture.png", sf::Vector2f t_defaultPosition = {2, 2}, int t_rarity = 1);
	~Weapon();
	int getDamage();
	//void setup(int t_radnomWeaponType);

private:
	int m_damage;

};

