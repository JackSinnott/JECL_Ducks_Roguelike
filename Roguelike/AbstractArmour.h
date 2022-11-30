#pragma once
#include "AbstractItem.h"
class AbstractArmour : public AbstractItem
{
public:
	~AbstractArmour() {};
	void SetType() { m_itemType = ItemType::Armour; };
	int GetArmour()
	{
		if (m_rarity > 3)
		{
			return m_armourClass * m_rarity / 2;
		}
		else
		{
			return m_armourClass;
		}
	};
protected:

	int m_armourClass = 0;
	Armours m_armourType;
};