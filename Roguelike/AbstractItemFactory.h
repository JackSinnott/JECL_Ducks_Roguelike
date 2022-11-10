#pragma once
#include "AbstractWeapon.h"
#include "Globals.h"
class AbstractItemFactory
{
public:
	virtual AbstractWeapon* CreateWeapon(Weapons t_weapon) = 0;
};

