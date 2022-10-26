#pragma once
#include "Item.h"
class Scroll : public Item
{
	Scroll(std::string imageName = "MissingTexture.png", sf::Vector2f defaultPosition = { 2, 2 }, int t_rarity = 1);
	~Scroll();
};

