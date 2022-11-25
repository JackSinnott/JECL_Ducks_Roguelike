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
	Room(int t_id, sf::Vector2f t_roomPos);
	~Room();

	void update(sf::Time t_dt);
	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;

	void setUpTiles(TileType t_type, int row, int col);
	inline int getID() { return id; }

private:
	sf::Vector2f m_pos;

	std::shared_ptr<sf::Texture> m_pTexture;
	std::array<std::array<Tile, G_MAP_COLS>,G_MAP_ROWS> m_tiles;
	int id;
};

#endif // !ROOM_H


