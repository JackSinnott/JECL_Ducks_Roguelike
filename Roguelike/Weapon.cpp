#include "Weapon.h"

Weapon::Weapon(std::string imageName, sf::Vector2f defaultPosition, int t_rarity):Item(imageName,defaultPosition,t_rarity)
{
	setPosition();
}

Weapon::~Weapon()
{
}

void Weapon::setPosition()
{
	m_itemSprite.setPosition(100, G_CELL_SIZE / 2);
}
