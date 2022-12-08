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
	//std::cout << "tile at index [" << row << "],[" << col <<"] is located at : " << m_tiles[row][col].getGridPosition().x << m_tiles[row][col].getGridPosition().y << "\n";
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

	if (m_tiles[row][col].getType() != TileType::UNUSED && m_tiles[row][col].getType() != TileType::GROUND)
	{
		m_walls.push_back(m_tiles[row][col].getSprite());
	}

	m_tiles[row][col].setGridPosition();
}


void Room::setGridPosition()
{
	row = m_pos.x / G_CELL_SIZE;
	col = m_pos.y / G_CELL_SIZE;
}



