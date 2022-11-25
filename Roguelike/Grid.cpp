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

void Grid::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	t_target.draw(m_points);
	
	for (Room* r : m_rooms)
	{
		r->draw(t_target);
	}
}

void Grid::setUpRoom(TileType t_type, int t_roomID, int t_row, int t_col)
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

	if (!roomExists) // If room doesn't exist
	{
		Room* r = new Room(t_roomID, placeRoom());
		numOfRoomsMade++;
		m_rooms.push_back(r);
		// make a new room
	}
	m_rooms[m_rooms.size() - 1]->setUpTiles(t_type, t_row, t_col);
}

sf::Vector2f Grid::placeRoom()
{
	switch (numOfRoomsMade)
	{
	case 0:
		break;
	case 1:
		m_roomPos += sf::Vector2f(G_ROOM_ROWS * G_ROOM_ROWS + 16.f, G_ROOM_COLS * G_ROOM_COLS + 16.f);
	}
	return m_roomPos;
}


