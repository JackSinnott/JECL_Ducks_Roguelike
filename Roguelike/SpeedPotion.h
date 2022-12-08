#pragma once
#include "AbstractPotion.h"

class SpeedPotion : public AbstractPotion
{
public:
	/// <summary>
/// Sets up the potion type, how powerful it is as well as its basics
/// </summary>
/// <param name="t_potionType"></param>
	SpeedPotion(Potions t_potionType)
	{
		m_potionType = t_potionType;
		m_speed = 2 + rand() % 10;

		SetupBasics();
		SetType();
	};


	/// <summary>
	/// And overrided function that returns the speed effect
	/// </summary>
	/// <returns></returns>
	int UseEffect() override
	{
		return m_speed;
	}


private:
	int m_speed = 0;//Speed stat of the potion
};
