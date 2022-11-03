#include "Weapon.h"

Weapon::Weapon(Weapons t_weaponType, std::string imageName, sf::Vector2f defaultPosition, int t_rarity):Item(imageName,defaultPosition,t_rarity)
{
	
}

Weapon::~Weapon()
{
}

int Weapon::getDamage()
{
	return m_damage;
}