#pragma once

#include "AbstractItemFactory.h"
#include "HealthPotion.h"
#include "StrengthPotion.h"
#include "SpeedPotion.h"
class PotionFactory : public AbstractItemFactory
{
public:
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