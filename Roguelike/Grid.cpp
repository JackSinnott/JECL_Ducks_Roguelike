#include "Grid.h"
#include "Globals.h"

Grid::Grid(int t_x, int t_y) : x(t_x), y(t_y),m_playerRoom(0)
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

void Grid::update(sf::Time t_dt, Player &t_playerPos)
{
	for (Room* room : m_rooms)
	{
		room->update(t_dt, 1, 1);
		room->setGridPosition();
		getRoomPosition();
		checkCollisionPlayerWall(t_playerPos);
		room->CheckPlayer(m_playerRoom);
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
		//Creates new room with a set position created based on the number of rooms
		Room* r = new Room(t_roomID, placeRoom());
		numOfRoomsMade++;
		m_rooms.push_back(r);
		// make a new room
	}
	m_rooms[m_rooms.size() - 1]->setUpTiles(t_type, t_row, t_col);
}

void Grid::setUpWalls()
{
	for (Room* room : m_rooms)
	{
		m_roomWalls.emplace(room->getID(), room->getWalls());
	}
}

void Grid::getRoomPosition()
{
	for (Room* r : m_rooms)
	{
		//std::cout << "The current room positions are: { " << r->getGridPosition().x << " , " << r->getGridPosition().y << "}\n";
	}
}

Room* Grid::checkRoom(int t_roomID)
{
	return m_rooms.at(t_roomID);
}

int Grid::whatRoomIsPlayerIn(sf::Vector2i t_playerPos)
{
	m_playerRoom = -1;
	if (t_playerPos.x <= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_playerPos.y < m_rooms.at(2)->getGridPosition().y)
		{
			m_playerRoom = 1;
		}
	}
	if (t_playerPos.x >= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_playerPos.y < m_rooms.at(2)->getGridPosition().y)
		{
			m_playerRoom = 2;
		}
	}
	if (t_playerPos.x <= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_playerPos.y >= m_rooms.at(3)->getGridPosition().y)
		{
			m_playerRoom = 3;
		}
	}

	if (t_playerPos.x >= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_playerPos.y >= m_rooms.at(3)->getGridPosition().y)
		{
			m_playerRoom = 4;
		}
	}
	
	return m_playerRoom;
}

void Grid::checkCollisionPlayerWall(Player &t_player)
{
	if (m_playerRoom > 0 && m_playerRoom <= 4)
	{
		checkCollisionPlayerInRoom(t_player);
	}
	else
	{
		std::cout << "Where has our little player gone???? \n";
	}
}

sf::Vector2f Grid::placeRoom()
{
	switch (numOfRoomsMade)
	{
	case 0:
		break;
	case 1:
		m_roomPos += sf::Vector2f(800, 0);
		break;
	case 2:
		m_roomPos += sf::Vector2f(-800, 640);
		break;
	case 3:
		m_roomPos += sf::Vector2f(800, 0);
	}
	return m_roomPos;
}

void Grid::checkCollisionPlayerInRoom(Player& t_player)
{
	sf::Vector2i playerPos = t_player.getPlayerPositionInGrid();
	t_player.resetMovementBools(true);
	for (auto& m : m_roomWalls.at(m_playerRoom))
	{
		// moving right
		if (playerPos.y == m.y)
		{
			if (playerPos.x + 1 == m.x)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_player.setMovementBoolRight(false);
			}
		}
		// moving left
		if (playerPos.y == m.y)
		{
			if (playerPos.x - 1 == m.x)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_player.setMovementBoolLeft(false);
			}
		}
		// moving down
		if (playerPos.x == m.x)
		{
			if (playerPos.y + 1 == m.y)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_player.setMovementBoolDown(false);
			}
		}
		// moving up
		if (playerPos.x == m.x)
		{
			if (playerPos.y - 1 == m.y)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_player.setMovementBoolUp(false);
			}
		}
	}
}

