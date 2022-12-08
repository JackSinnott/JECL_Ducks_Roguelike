#pragma once
#include "AbstractPotion.h"

class HealthPotion : public AbstractPotion
{
public:
	/// <summary>
	/// Sets up the potion type, how powerful it is as well as its basics
	/// </summary>
	/// <param name="t_potionType"></param>
	HealthPotion(Potions t_potionType)
	{
		SetPotionType(t_potionType);
		m_healing = 5 + rand() % 10;

		SetupBasics();
		SetType();
	};

	/// <summary>
	/// And overrided function that returns the health effect
	/// </summary>
	/// <returns></returns>
	int UseEffect() override
	{
		return m_healing;
	}


private:
	int m_healing = 0;//Healing stat of hte potion
};
