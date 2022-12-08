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

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;
	 
	void update(sf::Time t_dt);

	void setUpRoom(TileType t_type, int t_roomID, int t_row, int t_col);


private:
	sf::Vector2f placeRoom();

	int x = 0;
	int y = 0;

	sf::Vector2f m_roomPos = sf::Vector2f();

	int numOfRoomsMade = 0;

	sf::Vertex m_point;
	sf::VertexArray m_points;

	std::vector<Room*> m_rooms;



};

#endif // !GRID_H
