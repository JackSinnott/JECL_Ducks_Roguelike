#pragma once
#include "AbstractItem.h"

class AbstractPotion : public AbstractItem
{
public:
	AbstractPotion()
	{
		if (m_rects.size() == 0)
		{
			m_rects.try_emplace(Potions::Speed, sf::IntRect{ 96,144,16,16 });
			m_rects.try_emplace(Potions::Health, sf::IntRect{ 112,144,16,16 });
			m_rects.try_emplace(Potions::Strength, sf::IntRect{ 128,144,16,16 });
		}
	}
	~AbstractPotion() {};
	virtual int UseEffect() = 0;
	void SetPotionType(Potions t_potionType) { m_potionType = t_potionType; };
	Potions GetPotionType() { return m_potionType; };

	void SetType() { m_itemType = ItemType::Potion;  m_itemSprite.setTextureRect(m_rects.at(m_potionType));};

protected:
	static std::unordered_map<Potions, sf::IntRect> m_rects;
	Potions m_potionType;
};
