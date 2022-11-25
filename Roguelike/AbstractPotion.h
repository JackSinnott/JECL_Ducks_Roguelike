#pragma once
#include "AbstractItem.h"

class AbstractPotion : public AbstractItem
{
public:
	~AbstractPotion() {};
	void SetType() { m_itemType = ItemType::Potion; };

protected:
	Potions m_potionType;
};
