#pragma once

#include "AbstractItemFactory.h"
#include "HealthPotion.h"
#include "StrengthPotion.h"
#include "SpeedPotion.h"
class PotionFactory : public AbstractItemFactory
{
public:
	/// <summary>
/// Default overloaded constructor
/// Creates a new potion object depending on what type of armour is passed in
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