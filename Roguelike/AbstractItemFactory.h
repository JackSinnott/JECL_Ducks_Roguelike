#pragma once
#include "AbstractWeapon.h"
#include "AbstractArmour.h"
#include "Globals.h"
class AbstractItemFactory
{
public:
	virtual AbstractWeapon* CreateWeapon(Weapons t_weapon) = 0;
	virtual AbstractArmour* CreateArmour(Armours t_armour) = 0;
};

