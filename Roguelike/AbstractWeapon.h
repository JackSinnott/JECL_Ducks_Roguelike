#pragma once
#include <SFML/Graphics.hpp>
class AbstractWeapon
{
public:
	~AbstractWeapon() {};
	virtual int Attack() = 0; //Returns the damage of the weapon
private:
	//Should this even be here?
	//int m_damage; //How much damage the weapon does.
	//int m_rarity; //How rare the weapon is. High rarity increases damage. Should be randomised.
};

