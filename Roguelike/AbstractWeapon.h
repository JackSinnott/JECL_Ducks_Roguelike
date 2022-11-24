#pragma once

#include "AbstractItem.h"
class AbstractWeapon : public AbstractItem
{
public:
	~AbstractWeapon() {};

	void SetType() { m_itemType = ItemType::Weapon; };
	virtual int GetDamage() { return m_damage; }; //Returns the damage of the weapon

protected:
	int m_damage = 0; //How much damage the weapon does.
	Weapons m_weaponType;
};

