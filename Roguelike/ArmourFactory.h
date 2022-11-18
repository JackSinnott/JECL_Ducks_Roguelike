#pragma once
#include "AbstractItemFactory.h"
#include "LightArmour.h"
#include "HeavyArmour.h"
#include "MediumArmour.h"
class ArmourFactory : public AbstractItemFactory
{
public:
	AbstractArmour* CreateArmour(Armours t_armour) override
	{
		switch (t_armour)
		{
		case Armours::Light:
			return new LightArmour(t_armour);
			break;
		case Armours::Medium:
			return new MediumArmour(t_armour);
			break;
		case Armours::Heavy:
			return new HeavyArmour(t_armour);
			break;
		default:
			return NULL;
			break;
		}
	};
};

