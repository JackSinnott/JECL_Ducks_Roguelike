#pragma once
#include "AbstractItem.h"

/// <summary>
/// An abstract potion that HealthPotion, SpeedPotion, and StrengthPotion derive from.
/// </summary>

class AbstractPotion : public AbstractItem
{
public:

	/// <summary>
	/// Default Class Constructor.
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

	/// <summary>
	/// Default Class Deconstructor.
	/// </summary>
	~AbstractPotion() {};

	/// <summary>
	/// Pure virtual function where all potions can use it for different effects.
	/// </summary>
	/// <returns>The value passed, depending on the type of potion used.</returns>
	virtual int UseEffect() = 0;

	/// <summary>
	/// Sets the potion's type.
	/// </summary>
	/// <param name="t_potionType">The type of potion this is.</param>
	void SetPotionType(Potions t_potionType) { m_potionType = t_potionType; };


	/// <summary>
	/// Returns the potion's type.
	/// </summary>
	/// <returns>The type of potion this is.</returns>
	Potions GetPotionType() { return m_potionType; };

	/// <summary>
	/// Sets the type of item it is, as well as setting its sprite.
	/// </summary>
	void SetType() { m_itemType = ItemType::Potion;  m_itemSprite.setTextureRect(m_rects.at(m_potionType));};

protected:

	/// <summary>
	/// The sprite rects of the potions.
	/// </summary>
	static std::unordered_map<Potions, sf::IntRect> m_rects;

	///The type of potion this object is - Strength, Health or Speed.
	Potions m_potionType = Potions::Health;
};
