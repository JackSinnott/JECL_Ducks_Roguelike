#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <array>

struct Tile
{
	int x = 0, y = 0;
	sf::Vector2f position{ x,y };
	sf::Sprite m_tileSprite;
	TileType m_type;
};

class Room
{
public:
	Room(int t_x = 0, int t_y = 0, int t_id = 0);
	~Room();

	void update(sf::Time t_dt);
	void draw(sf::RenderWindow& m_win);

	void setUpTiles(sf::Vector2f t_pos, TileType t_type, int row, int col);
	inline int getID() { return id; }

private:
	std::array<std::array<Tile, G_MAP_COLS>,G_MAP_ROWS> m_tiles;
	int x = 0, y = 0;
	sf::Vector2f position{ x, y };
	int id;
};

#endif // !ROOM_H


