#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Room.h"

class Grid
{
public:
	Grid(int t_x, int t_y);
	inline ~Grid() {};

	void draw(sf::RenderWindow& m_win);

	void setUpRoom(sf::Vector2f t_position, TileType t_type, int t_roomID);


private:
	int x = 0;
	int y = 0;

	sf::Vertex m_point;
	sf::VertexArray m_points;

	std::vector<Room> m_rooms;

};

#endif // !GRID_H
