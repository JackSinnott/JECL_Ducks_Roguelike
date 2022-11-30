#pragma once
#include "AbstractItem.h"

class AbstractPotion : public AbstractItem
{
public:
	~AbstractPotion() {};
	void SetType() { m_itemType = ItemType::Potion; };
	virtual int UseEffect() = 0;
	void SetPotionType(Potions t_potionType) { m_potionType = t_potionType; };
	Potions GetPotionType() { return m_potionType; };
protected:
	Potions m_potionType;
};
