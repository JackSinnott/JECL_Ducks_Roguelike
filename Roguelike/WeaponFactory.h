#pragma once
#include "AbstractItemFactory.h"
#include "AxeWeapon.h"
#include "DaggerWeapon.h"
#include "SwordWeapon.h"

/// <summary>
/// Factory class that allows the enum of #Weapons to be made into an AbstractWeapon.
/// </summary>

class WeaponFactory : public AbstractItemFactory
{
public:
/// <summary>
/// Default overloaded constructor, that creates a new AbstractWeapon object depending on what type of #Weapons enum is passed in.
/// </summary>
/// <param name="t_armourType"></param>
	AbstractWeapon* CreateWeapon(Weapons t_weapon) override
	{
		switch (t_weapon)
		{
		case Weapons::Sword:
			return new SwordWeapon(t_weapon);
			break;
		case Weapons::Axe:
			return new AxeWeapon(t_weapon);
			break;
		case Weapons::Dagger:
			return new DaggerWeapon(t_weapon);
			break;
		default:
			return NULL;
			break;
		}
	};
};

