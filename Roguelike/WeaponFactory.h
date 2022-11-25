#pragma once
#include "AbstractItemFactory.h"
#include "AxeWeapon.h"
#include "DaggerWeapon.h"
#include "SwordWeapon.h"
class WeaponFactory : public AbstractItemFactory
{
public:
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

