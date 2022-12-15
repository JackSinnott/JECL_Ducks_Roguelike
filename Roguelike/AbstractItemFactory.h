#pragma once
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"


/// <summary>
/// An abstract item factory, that allows the generation of AbstractItem objects.
/// WeaponFactory, ArmourFactory and PotionFactory all derive from this.
/// </summary>

class AbstractItemFactory
{
public:
	///Virtual function where the item factory can create weapons.
	virtual AbstractWeapon* CreateWeapon(Weapons t_weapon) { return NULL;};

	///Virtual function where the item factory can create armours.
	virtual AbstractArmour* CreateArmour(Armours t_armour) { return NULL;};

	///Virtual function where the item factory can create potion.
	virtual AbstractPotion* CreatePotion(Potions t_potion) { return NULL;};
};

