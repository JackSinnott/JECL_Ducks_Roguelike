#pragma once
#include "AbstractItemFactory.h"
#include "HealthPotion.h"
#include "StrengthPotion.h"
#include "SpeedPotion.h"

/// <summary>
/// Factory class that allows the enum of #Potions to be made into an AbstractPotion.
/// </summary>

class PotionFactory : public AbstractItemFactory
{
public:

/// <summary>
/// Overloaded constructor, that creates a new AbstractPotion object depending on what type of #Potions enum is passed in.
/// </summary>
/// <param name="t_armourType"></param>
	AbstractPotion* CreatePotion(Potions t_potion) override
	{
		switch (t_potion)
		{
		case Potions::Health:
			return new HealthPotion(t_potion);
			break;
		case Potions::Strength:
			return new StrengthPotion(t_potion);
			break;
		case Potions::Speed:
			return new SpeedPotion(t_potion);
			break;
		default:
			return NULL;
			break;
		}
	}

};