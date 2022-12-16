#include "Room.h"

/// <summary>
/// Overloaded Class Constructor.
/// </summary>
/// <param name="t_id">This Room's new ID.</param>
/// <param name="t_pos">This Room's new position.</param>
Room::Room(int t_id, sf::Vector2f t_pos = sf::Vector2f()) :
	id(t_id),
	m_pos(t_pos)
{
	m_pTexture = TextureManager::Acquire("ASSETS//IMAGES//Level//MapTiles.png");
}

/// <summary>
/// Default deconstructor.
/// </summary>
Room::~Room()
{
}	

/// <summary>
/// Updates the Tile objects.
/// </summary>
/// <param name="t_dt">The time that has passed since last frame.</param>
/// <param name="row">The row this Room takes in a 3x3 layout, compared to other rooms.</param>
/// <param name="col">The column this Room takes in a 3x3 layout, compared to other rooms.</param>
void Room::update(sf::Time t_dt, int row, int col)
{
	//std::cout << "tile at index [" << row << "],[" << col <<"] is located at : " << m_tiles[row][col].getGridPosition().x << m_tiles[row][col].getGridPosition().y << "\n";

}

/// <summary>
/// Draws all the Tile objects to the screen.
/// </summary>
/// <param name="t_target">Where to draw the Tiles.</param>
/// <param name="t_state">The state in which to draw the Tiles.</param>
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
/// Checks if the Player has entered this Room.
/// </summary>
/// <param name="t_playerRoomID">The ID of the Room the Player currently is in.</param>
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
///Sets up a Tile object in this room.
/// </summary>
/// <param name="t_type">The type of Tile this one is.</param>
/// <param name="row">The row that this Tile will be at, in this Room.</param>
/// <param name="col">The column that this Tile will be at, in this Room.</param>
void Room::setUpTiles(TileType t_type, int row, int col) // pass argument that is GameData (aka whats loaded)
{
	m_tiles[row][col].setup(m_pTexture, sf::Vector2f{ static_cast<float>(row * G_CELL_SIZE), static_cast<float>(col * G_CELL_SIZE) }, m_pos, t_type);

	m_tiles[row][col].setGridPosition();

	if (m_tiles[row][col].getType() != TileType::UNUSED && m_tiles[row][col].getType() != TileType::GROUND && m_tiles[row][col].getType() != TileType::ENTRANCE)
	{
		m_walls.push_back(m_tiles[row][col].getGridPosition());
	}

	if (m_tiles[row][col].getType() == TileType::ENTRANCE)
	{
		m_entrances.push_back(m_tiles[row][col].getGridPosition());
	}

}

/// <summary>
/// Sets up the rows and columns this Tile occupies, for easy returns later.
/// </summary>
void Room::setGridPosition()
{
	row = m_pos.x / G_CELL_SIZE;
	col = m_pos.y / G_CELL_SIZE;
}


