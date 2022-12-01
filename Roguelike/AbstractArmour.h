#pragma once
#include "AbstractItem.h"
class AbstractArmour : public AbstractItem
{
public:

	AbstractArmour()
	{
		if (m_rects.size() == 0)
		{
			m_rects.try_emplace(Armours::Heavy, sf::IntRect{ 0,128,16,16 });
			m_rects.try_emplace(Armours::Medium, sf::IntRect{ 0,176,16,16 });
			m_rects.try_emplace(Armours::Light, sf::IntRect{ 16,176,16,16 });
		}


	}
	~AbstractArmour() {};
	void SetType() { m_itemType = ItemType::Armour; m_itemSprite.setTextureRect(m_rects.at(m_armourType)); };
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

	static std::unordered_map<Armours, sf::IntRect> m_rects;

	int m_armourClass = 0;
	Armours m_armourType;
};