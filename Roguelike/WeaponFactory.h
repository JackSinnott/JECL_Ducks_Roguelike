#pragma once
#include "AbstractItemFactory.h"
#include "AxeWeapon.h"
#include "DaggerWeapon.h"
#include "SwordWeapon.h"
class WeaponFactory : public AbstractItemFactory
{
public:
/// <summary>
/// Default overloaded constructor
/// Creates a new weapon object depending on what type of armour is passed in
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

