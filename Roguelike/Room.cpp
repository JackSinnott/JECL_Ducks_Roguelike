#include "Room.h"

Room::Room(int t_x, int t_y, int t_id) :
	x(t_x),
	y(t_y),
	id(t_id)
{
	m_pTexture = TextureManager::Acquire("ASSETS//IMAGES//Level//MapTiles.png");
}

Room::~Room()
{
}	

void Room::update(sf::Time t_dt)
{
}

void Room::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	for (auto& row : m_tiles)
		for (auto& x : row)
			t_target.draw(x, t_state);
}

void Room::setUpTiles(sf::Vector2f t_pos, TileType t_type, int row, int col) // pass argument that is GameData (aka whats loaded)
{

	m_tiles[row][col].setup(m_pTexture, sf::Vector2f{ static_cast<float>(row * G_CELL_SIZE), static_cast<float>(col * G_CELL_SIZE) }, t_type);

	// call tile setUp function

	// Figure out the num of tiles in row/col
	// Assign textures to sprites in tiles

}