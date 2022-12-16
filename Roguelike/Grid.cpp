#include "Grid.h"
#include "Globals.h"

/// <summary>
/// Overloaded Constructor of Grid.
/// </summary>
/// <param name="t_x">The starting X position of the Grid (ie. the left side).</param>
/// <param name="t_y">The starting Y position of the Grid (ie. the top).</param>
Grid::Grid() : m_playerRoom(0)
{
	int x = 0;
	int y = 0;

	sf::Vertex m_point;
	m_point.color = sf::Color::Red;

	for (int i = 0; i < G_MAP_COLS; i++)
	{
		for (int k = 0; k < G_MAP_ROWS; k++)
		{
			x = k * G_CELL_SIZE;
			y = i * G_CELL_SIZE;

			m_point.position = sf::Vector2f(x, y);
			m_points.append(m_point);
		}
	}

}

/// <summary>
/// Draws the rooms out onto the SFML screen.
/// </summary>
/// <param name="t_target">Where to draw the Rooms.</param>
/// <param name="t_state">The state in which to draw the Rooms.</param>
void Grid::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	t_target.draw(m_points);
	
	for (Room* r : m_rooms)
	{
		r->draw(t_target);
	}
}

/// <summary>
/// Updates the Grid, meaning it updates the appearance of the room, and checks Player collisons with the Tiles.
/// </summary> 
/// <param name="t_dt">The time that has passed since last frame.</param>
/// <param name="t_playerPos">A reference to the Player in Gameplay.</param>
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

/// <summary>
/// Sets up a Tile in a Room.
/// </summary>
/// <param name="t_type">The type of Tile that is being placed.</param>
/// <param name="t_roomID">The ID of the Room that the Tile is being placed in.</param>
/// <param name="t_row">The row the Tile will have in the Room. This can range from 0 to 24.</param>
/// <param name="t_col">The column the Tile will have in the Room. This can range from 0 to 19.</param>
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

/// <summary>
/// Gets all the impassible Tiles from the Room objects, and copies them, so Grid now knows 
/// where all collisions should occur.
/// </summary>
void Grid::setUpWalls()
{
	for (Room* room : m_rooms)
	{
		m_roomWalls.emplace(room->getID(), room->getWalls());
	}
}

/// <summary>
/// Prints all Rooms' positions to the console. Used for debugging.
/// </summary>
void Grid::getRoomPosition()
{
	for (Room* r : m_rooms)
	{
		//std::cout << "The current room positions are: { " << r->getGridPosition().x << " , " << r->getGridPosition().y << "}\n";
	}
}

/// <summary>
/// Returns a reference to a Room, by sending in the corresponding ID.
/// </summary>
/// <param name="t_roomID">The ID of the room.</param>
/// <returns>The reference to the Room.</returns>
Room* Grid::checkRoom(int t_roomID)
{
	return m_rooms.at(t_roomID);
}

/// <summary>
/// Calculates what Room the Player is in.
/// </summary>
/// <param name="t_playerPos">Player's row and column within the Grid.</param>
/// <returns>What Room the Player is currently in.</returns>
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

/// <summary>
/// Calculates what Room the target (ie the player) is in.
/// </summary>
/// <param name="t_targetPos">The target's position.</param>
/// <returns>The room that the target is in.</returns>
int Grid::whatRoomIsTargetIn(sf::Vector2i t_targetPos)
{
	int room = -1;
	if (t_targetPos.x <= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_targetPos.y < m_rooms.at(2)->getGridPosition().y)
		{
			room = 1;
		}
	}
	if (t_targetPos.x >= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_targetPos.y < m_rooms.at(2)->getGridPosition().y)
		{
			room = 2;
		}
	}
	if (t_targetPos.x <= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_targetPos.y >= m_rooms.at(3)->getGridPosition().y)
		{
			room = 3;
		}
	}

	if (t_targetPos.x >= m_rooms.at(1)->getGridPosition().x)
	{
		if (t_targetPos.y >= m_rooms.at(3)->getGridPosition().y)
		{
			room = 4;
		}
	}

	return room;
}

/// <summary>
/// Makes sure the Player is in boundaries. before checking if they collided with walls.
/// </summary>
/// <param name="t_player">A reference to the Player in Gameplay.</param>
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

/// <summary>
/// Makes sure the Enemy is in boundaries. before checking if they collided with walls.
/// </summary>
/// <param name="t_enemy">A reference to the Enemy in Gameplay.</param>
/// <param name="t_room">The room that the enemy is currently in.</param>
void Grid::checkCollisionEnemyWall(Enemy& t_enemy, int t_room)
{
	if (t_room > 0 && t_room <= 4)
	{
		checkCollisionEnemyInRoom(t_enemy, t_room);
	}
	else
	{
		std::cout << "Where has our little enemy gone???? \n";
	}
}

/// <summary>
/// Gets a position for a new room, depending on how many rooms are currently spawned in.
/// </summary>
/// <returns>The position of the Room in the Game.</returns>
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

/// <summary>
/// Checks if the Player has collided with any of the wall Tile objects.
/// </summary>
/// <param name="t_player"></param>
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

/// <summary>
/// Checks if the Enemy has collided with any of the wall Tile objects.
/// </summary>
/// <param name="t_enemy">A reference to the Enemy in Gameplay.</param>
/// <param name="t_room">The room that the enemy is currently in.</param>
void Grid::checkCollisionEnemyInRoom(Enemy& t_enemy, int t_room)
{
	sf::Vector2i enemyPos = t_enemy.getEnemyPositionInGrid();
	t_enemy.resetMovementBools(true);
	for (auto& m : m_roomWalls.at(t_room))
	{
		// moving right
		if (enemyPos.y == m.y)
		{
			if (enemyPos.x + 1 == m.x)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_enemy.setMovementBoolRight(false);
			}
		}
		// moving left
		if (enemyPos.y == m.y)
		{
			if (enemyPos.x - 1 == m.x)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_enemy.setMovementBoolLeft(false);
			}
		}
		// moving down
		if (enemyPos.x == m.x)
		{
			if (enemyPos.y + 1 == m.y)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_enemy.setMovementBoolDown(false);
			}
		}
		// moving up
		if (enemyPos.x == m.x)
		{
			if (enemyPos.y - 1 == m.y)
			{
				//std::cout << "aghhhh we collided!!!! \n player row in question: " << playerPos.x + 1 << "\n wall row in question: " << m.x << "\n";
				t_enemy.setMovementBoolUp(false);
			}
		}
	}
}

