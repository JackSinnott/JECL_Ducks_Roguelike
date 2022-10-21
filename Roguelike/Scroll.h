#pragma once
#include "Item.h"
class Scroll : public Item
{
public:
	Scroll(std::string imageName = "MissingTexture.png", sf::Vector2f defaultPosition = { 2, 2 }, int t_rarity = 1);
	~Scroll();
private:
	int m_fireBallDamage;
	int m_invincibilityTimer;
	sf::Vector2f m_teleportation;
};

