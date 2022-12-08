#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include "SFML/Graphics.hpp"
#include <iostream>

class CollisionHandler
{
public:
	CollisionHandler();

	void update(sf::Vector2i(t_playerPos));

	bool checkCollisonWithWall(int t_PlayerRoom);

private:
	sf::Vector2i m_playerPos;
	std::vector<sf::Vector2i> m_surroundingTiles;
};

#endif // !COLLISION_HANDLER_H


