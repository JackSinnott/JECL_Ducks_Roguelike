#include "Room.h"

/// <summary>
/// 
/// </summary>
/// <param name="t_id"></param>
/// <param name="t_pos"></param>
Room::Room(int t_id, sf::Vector2f t_pos = sf::Vector2f()) :
	id(t_id),
	m_pos(t_pos)
{
	m_pTexture = TextureManager::Acquire("ASSETS//IMAGES//Level//MapTiles.png");
}

/// <summary>
/// 
/// </summary>
Room::~Room()
{
}	

/// <summary>
/// 
/// </summary>
/// <param name="t_dt"></param>
/// <param name="row"></param>
/// <param name="col"></param>
void Room::update(sf::Time t_dt, int row, int col)
{
	//std::cout << "tile at index [" << row << "],[" << col <<"] is located at : " << m_tiles[row][col].getGridPosition().x << m_tiles[row][col].getGridPosition().y << "\n";

}

/// <summary>
/// 
/// </summary>
/// <param name="t_target"></param>
/// <param name="t_state"></param>
void Room::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	if (m_revealed)
	{
		for (auto& row : m_tiles)
			for (auto& x : row)
				t_target.draw(x, t_state);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="t_playerRoomID"></param>
void Room::CheckPlayer(int t_playerRoomID)
{
	if (m_revealed == false && t_playerRoomID == id)
	{
		m_revealed = true;
		std::cout << "Player entered new room!" << std::endl;
		std::cout << "The player is in room: " << t_playerRoomID << std::endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="t_type"></param>
/// <param name="row"></param>
/// <param name="col"></param>
void Room::setUpTiles(TileType t_type, int row, int col) // pass argument that is GameData (aka whats loaded)
{
	m_tiles[row][col].setup(m_pTexture, sf::Vector2f{ static_cast<float>(row * G_CELL_SIZE), static_cast<float>(col * G_CELL_SIZE) }, m_pos, t_type);

	m_tiles[row][col].setGridPosition();

	if (m_tiles[row][col].getType() != TileType::UNUSED && m_tiles[row][col].getType() != TileType::GROUND)
	{
		m_walls.push_back(m_tiles[row][col].getGridPosition());
	}

}

/// <summary>
/// 
/// </summary>
void Room::setGridPosition()
{
	row = m_pos.x / G_CELL_SIZE;
	col = m_pos.y / G_CELL_SIZE;
}


