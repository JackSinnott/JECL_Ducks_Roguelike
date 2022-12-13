#pragma once
#include "AbstractItem.h"

/// <summary>
/// The Abstract class that is the base for the LightArmour, HeavyArmour, and MediumArmour classes.
/// </summary>

class AbstractArmour : public AbstractItem
{
public:

	/// <summary>
	///	Default class constructor.
	/// </summary>
	AbstractArmour()
	{
		if (m_rects.size() == 0)
		{
			m_rects.try_emplace(Armours::Heavy, sf::IntRect{ 0,128,16,16 });
			m_rects.try_emplace(Armours::Medium, sf::IntRect{ 0,176,16,16 });
			m_rects.try_emplace(Armours::Light, sf::IntRect{ 16,176,16,16 });
		}


	}

	/// <summary>
	///	Default class deconstructor.
	/// </summary>
	~AbstractArmour() {};

	/// <summary>
	/// Sets the type of item this object is, as well as setting its sprite.
	/// </summary>
	void SetType() { m_itemType = ItemType::Armour; m_itemSprite.setTextureRect(m_rects.at(m_armourType)); };

	/// <summary>
	/// Gets the armour type of this object.
	/// </summary>
	/// <returns>The Armour type.</returns>
	Armours GetType() { return m_armourType; };


	/// <summary>
	/// Gets the armour class.
	/// </summary>
	/// <returns>The armour class (AC) of this armour.</returns>
	int GetArmourClass()
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

	/// <summary>
	/// The sprite rects of the armour.
	/// </summary>
	static std::unordered_map<Armours, sf::IntRect> m_rects;

	int m_armourClass = 0; ///The armour class.
	Armours m_armourType = Armours::Light; ///The armour type.
};