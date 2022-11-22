#include "Room.h"

Room::Room(int t_x, int t_y, int t_width, int t_height, int t_id) :
	x(t_x), 
	y(t_y), 
	height(t_height), 
	width(t_width),
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
	for (Tile t : m_tiles)
	{
		m_win.draw(t.m_tileSprite);
	}
}

void Room::setUpTiles() // pass argument that is GameData (aka whats loaded)
{
	// Figure out the num of tiles in row/col

	// Set positions in tiles

	// Assign textures to sprites in tiles

	//assign types
}
