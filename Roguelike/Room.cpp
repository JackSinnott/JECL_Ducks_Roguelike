#include "Room.h"

Room::Room(int t_x, int t_y, int t_id) :
	x(t_x), 
	y(t_y),
	id(t_id)
{

}

Room::~Room()
{
}

void Room::update(sf::Time t_dt)
{
}

void Room::draw(sf::RenderWindow& m_win)
{
	/*for (std::vector<Tile> lineOfTiles : m_tiles)
	{
		for (Tile tile : lineOfTiles)
		{
			m_win.draw(tile.m_tileSprite);
		}
	}*/

}

void Room::setUpTiles(sf::Vector2f t_pos, TileType t_type, int row, int col) // pass argument that is GameData (aka whats loaded)
{
	Tile newTile;
	// Set positions in tiles
	newTile.position = t_pos;

	//assign types
	newTile.m_type = t_type;

	m_tiles[row][col] = newTile;


	// Figure out the num of tiles in row/col
	// Assign textures to sprites in tiles

	
}
