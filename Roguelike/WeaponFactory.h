#pragma once
#include "AbstractItemFactory.h"

class WeaponFactory : public AbstractItemFactory
{
public:
	AbstractWeapon* CreateWeapon(Weapons t_weapon) override
	{
		switch (t_weapon)
		{
		case Weapons::Sword:
			return NULL;
			break;
		case Weapons::Axe:
			return NULL;
			break;
		case Weapons::Dagger:
			return NULL;
			break;
		}
	};

};

