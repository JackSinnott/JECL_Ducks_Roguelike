#pragma once
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"

#include "Globals.h"

/// <summary>
/// An abstract item factory
/// </summary>
class AbstractItemFactory
{
public:
	virtual AbstractWeapon* CreateWeapon(Weapons t_weapon) { return NULL;};//Virtual function where the item factory can create weapons
	virtual AbstractArmour* CreateArmour(Armours t_armour) { return NULL;};//Virtual function where the item factory can create armours
	virtual AbstractPotion* CreatePotion(Potions t_potion) { return NULL;};//Virtual function where the item factory can create potion
};

