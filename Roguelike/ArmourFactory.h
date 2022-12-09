#pragma once
#include "AbstractItemFactory.h"
#include "LightArmour.h"
#include "HeavyArmour.h"
#include "MediumArmour.h"
class ArmourFactory : public AbstractItemFactory
{
public:


	/// <summary>
	/// Default overloaded constructor
	/// Creates a new armour object depending on what type of armour is passed in
	/// </summary>
	/// <param name="t_armourType"></param>
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

