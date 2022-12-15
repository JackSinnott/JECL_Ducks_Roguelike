#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Room.h"
#include "Player.h"

/// <summary>
/// The Grid class - organises the Room objects, making sure that they're placed and updated correctly.
/// </summary>

class Grid
{
public:
	Grid();

	/// <summary>
	/// Default Deconstructor.
	/// </summary>
	inline ~Grid() {};

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;

	void update(sf::Time t_dt, Player &t_playerPos);

	void setUpRoom(TileType t_type, int t_roomID, int t_row, int t_col);

	void setUpWalls();

	void getRoomPosition();

	Room* checkRoom(int t_roomID);

	int whatRoomIsPlayerIn(sf::Vector2i t_playerPos);

	void checkCollisionPlayerWall(Player &t_player);

private:
	sf::Vector2f placeRoom();

	///The index of the room the Player is currently in.
	int m_playerRoom;

	///The current new position to place down Rooms. This updates every time a new Room is generated.
	sf::Vector2f m_roomPos = sf::Vector2f();

	///How many rooms are currently made on the Grid.
	int numOfRoomsMade = 0;

	///The dots on the map - used to signify the size and area covered by a Tile.
	sf::VertexArray m_points;

	///The Rooms themselves - stored as pointers.
	std::vector<Room*> m_rooms;

	///All the impassable areas of the game.
	std::map<int, std::vector<sf::Vector2i>> m_roomWalls;
};

#endif // !GRID_H
