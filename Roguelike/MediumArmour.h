#pragma once
#include "AbstractArmour.h"
class MediumArmour : public AbstractArmour
{
public:
	MediumArmour(Armours t_armourType)
	{
		m_armourType = t_armourType;
		m_armourClass = 10;
		m_rarity = rand() % 10 + 1;
		SetupBasics();
		SetType();
	};
};

