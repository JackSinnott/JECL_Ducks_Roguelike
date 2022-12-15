#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Room.h"
#include "Player.h"

class Grid
{
public:
	Grid(int t_x, int t_y);
	inline ~Grid() {};

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;

	void update(sf::Time t_dt, Player &t_playerPos);

	void setUpRoom(TileType t_type, int t_roomID, int t_row, int t_col);

	void setUpWalls();

	void getRoomPosition();

	Room* checkRoom(int t_roomID);

	int whatRoomIsPlayerIn(sf::Vector2i t_playerPos);

	void checkCollisionPlayerWall(Player &t_player);

	std::vector<Room*> &GetRooms();

	void CheckCollisionItems(Player t_player);
private:
	sf::Vector2f placeRoom();

	int x = 0;
	int y = 0;
	int m_playerRoom;

	sf::Vector2f m_roomPos = sf::Vector2f();

	int numOfRoomsMade = 0;

	sf::Vertex m_point;
	sf::VertexArray m_points;

	std::vector<Room*> m_rooms;
	std::map<int, std::vector<sf::Vector2i>> m_roomWalls;

	Player m_player;

};

#endif // !GRID_H
