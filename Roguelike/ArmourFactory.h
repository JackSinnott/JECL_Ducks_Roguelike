#pragma once
#include "AbstractItemFactory.h"
#include "LightArmour.h"
#include "HeavyArmour.h"
#include "MediumArmour.h"

/// <summary>
/// Factory class that allows the enum of #Armour to be made into an AbstractArmour.
/// </summary>

class ArmourFactory : public AbstractItemFactory
{
public:

	/// <summary>
	/// Overloaded constructor, that creates a new AbstractArmour object depending on what type of #Armours enum is passed in.
	/// </summary>
	/// <param name="t_armour">The enum type of the armour.</param>
	/// <returns>The new armour object that was created.</returns>
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

