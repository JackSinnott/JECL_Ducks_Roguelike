#pragma once
#include "AbstractItem.h"

class AbstractPotion : public AbstractItem
{
public:
	~AbstractPotion() {};
	
	int GetPotion()
	{
		return 0;
	}

protected:
	Potions m_potionType;
};
