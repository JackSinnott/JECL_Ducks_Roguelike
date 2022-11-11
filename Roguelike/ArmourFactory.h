#pragma once
#include "AbstractItemFactory.h"
#include "LightArmour.h"
class ArmourFactory : public AbstractItemFactory
{
public:
	/*AbstractArmour* CreateArmour(Armours t_armour) override
	{
		switch (t_armour)
		{
		case Armours::Light:
			return new LightArmour(t_armour);
			break;
		case Armours::Medium:
			return NULL;
			break;
		case Armours::Heavy:
			return NULL;
			break;
		default:
			return NULL;
			break;
		}
	};*/

};

