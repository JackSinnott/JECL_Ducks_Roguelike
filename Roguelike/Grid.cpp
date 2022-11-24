#include "Grid.h"
#include "Globals.h"

Grid::Grid(int t_x, int t_y) : x(t_x), y(t_y)
{
	for (int i = 0; i < G_MAP_COLS; i++)
	{
		for (int k = 0; k < G_MAP_ROWS; k++)
		{
			x = k * G_CELL_SIZE;
			y = i * G_CELL_SIZE;

			m_point.position = sf::Vector2f(x, y);
			m_point.color = sf::Color::Red;
			m_points.append(m_point);
			
		}
	}
}

void Grid::draw(sf::RenderWindow& m_win)
{
	m_win.draw(m_points);
}

void Grid::setUpRoom(sf::Vector2f t_position, TileType t_type, int t_roomID)
{
	bool roomExists = false;

	for (Room* oneRoom : m_rooms)
	{
		if (oneRoom->getID() == t_roomID) // id == t_roomID
		{
			roomExists = true;
			break;
		}
	}

	if (!roomExists) // If room already exists 
	{
		Room* r = new Room();

		m_rooms.push_back(r);
		// make a new room
	}
	
	//m_rooms[t_roomID].setUpTiles();
}
