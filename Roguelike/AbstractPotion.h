#pragma once
#include "AbstractItem.h"

class AbstractPotion : public AbstractItem
{
public:
	/// <summary>
	/// Abstract potion all potion items derive from
	/// </summary>
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

	/// <summary>
	/// Pure virtual function where all potions can use it for different effects
	/// </summary>
	/// <returns></returns>
	virtual int UseEffect() = 0;

	/// <summary>
	/// Sets the potion's type
	/// </summary>
	/// <param name="t_potionType"></param>
	void SetPotionType(Potions t_potionType) { m_potionType = t_potionType; };


	/// <summary>
	/// Returns the potion's type
	/// </summary>
	/// <returns></returns>
	Potions GetPotionType() { return m_potionType; };

	/// <summary>
	/// Sets the type of item it is as well as setting its sprite
	/// </summary>
	void SetType() { m_itemType = ItemType::Potion;  m_itemSprite.setTextureRect(m_rects.at(m_potionType));};

protected:
	static std::unordered_map<Potions, sf::IntRect> m_rects;
	Potions m_potionType; // The type of potion it is
};
