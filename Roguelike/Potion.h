#pragma once
#include "Item.h"
class Potion : public Item
{
	Potion(std::string imageName = "MissingTexture.png", sf::Vector2f defaultPosition = { 2, 2 });
	~Potion();
};

