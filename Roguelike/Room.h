#ifndef ROOM_H
#define ROOM_H

#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <array>
#include "Tile.h"

class Room
{
public:
	Room(int t_id, int t_x = 0, int t_y = 0);
	~Room();

	void update(sf::Time t_dt);
	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;

	void setUpTiles(sf::Vector2f t_pos, TileType t_type, int row, int col);
	inline int getID() { return id; }

private:
	std::shared_ptr<sf::Texture> m_pTexture;
	std::array<std::array<Tile, G_MAP_COLS>,G_MAP_ROWS> m_tiles;
	int x = 0, y = 0;
	sf::Vector2f position{ x, y };
	int id;
};

#endif // !ROOM_H


