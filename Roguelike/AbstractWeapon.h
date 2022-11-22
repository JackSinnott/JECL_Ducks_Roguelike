#pragma once

#include "AbstractItem.h"
class AbstractWeapon : public AbstractItem
{
public:
	~AbstractWeapon() {};
	virtual int GetDamage() = 0; //Returns the damage of the weapon

protected:
	int m_damage; //How much damage the weapon does.
	int m_rarity; //How rare the weapon is. High rarity increases damage. Should be randomised.
	Weapons m_weaponType;
};

