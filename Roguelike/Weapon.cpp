#include "Weapon.h"

Weapon::Weapon(std::string imageName, sf::Vector2f defaultPosition, int t_rarity):Item(imageName,defaultPosition,t_rarity)
{
	
}

Weapon::~Weapon()
{
}

int Weapon::getDamage()
{
	return m_damage;
}

//void Weapon::setup()
//{
//	switch (Weapons)
//	{
//	case Weapons::Sword:
//		break;
//	case Weapons::Axe:
//		break;
//	case Weapons::Dagger:
//		break;
//	default:
//		break;
//	}
//}
