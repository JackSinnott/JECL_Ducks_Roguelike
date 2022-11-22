#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include "Globals.h"

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
	Room(int t_x = 0, int t_y = 0, int t_width = 0, int t_height = 0, int t_id = 0);
	~Room();

	void update(sf::Time t_dt);
	void draw(sf::RenderWindow& m_win);

	void setUpTiles();
	inline int getID() { return id; }

private:
	std::vector<Tile> m_tiles;
	int x, y;
	sf::Vector2f position{ x, y };
	int width, height;
	int id;
};

#endif // !ROOM_H


