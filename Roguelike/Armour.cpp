#include "Armour.h"

Armour::Armour(std::string imageName, sf::Vector2f defaultPosition, int t_rarity) :Item(imageName, defaultPosition, t_rarity)
{

}

Armour::~Armour()
{

}

int Armour::getArmourRating()
{
    return m_armourRating;
}
