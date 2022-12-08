#include "Room.h"

Room::Room(int t_id, sf::Vector2f t_pos = sf::Vector2f()) :
	id(t_id),
	m_pos(t_pos)
{
	m_pTexture = TextureManager::Acquire("ASSETS//IMAGES//Level//MapTiles.png");
}

Room::~Room()
{
}	

void Room::update(sf::Time t_dt, int row, int col)
{
	//std::cout << "tile at index [24][19] is located at: " << m_tiles[row][col].getPosition().x << m_tiles[row][col].getPosition().y << "\n";
}

void Room::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	for (auto& row : m_tiles)
		for (auto& x : row)
			t_target.draw(x, t_state);
}

void Room::setUpTiles(TileType t_type, int row, int col) // pass argument that is GameData (aka whats loaded)
{
	m_tiles[row][col].setup(m_pTexture, sf::Vector2f{ static_cast<float>(row * G_CELL_SIZE), static_cast<float>(col * G_CELL_SIZE) }, m_pos, t_type);
}
