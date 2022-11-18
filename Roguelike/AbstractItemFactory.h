#pragma once
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "AbstractPotion.h"

#include "Globals.h"
class AbstractItemFactory
{
public:
	virtual AbstractWeapon* CreateWeapon(Weapons t_weapon) { return NULL;};
	virtual AbstractArmour* CreateArmour(Armours t_armour) { return NULL;};
	virtual AbstractPotion* CreatePotion(Potions t_potion) { return NULL;};
};

