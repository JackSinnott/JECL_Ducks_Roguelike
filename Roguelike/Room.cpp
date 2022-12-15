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
	srand(time(0));

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

		for (AbstractItem* n : m_absItemVector)
		{
			t_target.draw(n->GetSprite());
		}
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

void Room::SpawnItems(int t_row, int t_col)
{

	int randomChance = rand() % 10 + 1;
	int randomChanceB = rand() % 3 + 1;

	if (randomChance > 8 && m_tiles[t_row][t_col].TileOccupied() == false)
	{
		int n = rand() % 3;
		Weapons w;
		Armours a;
		Potions p;


		switch (randomChanceB)
		{
		case 1:
			m_itemfactory = new WeaponFactory();

			w = static_cast<Weapons>(n);

			m_absItem = m_itemfactory->CreateWeapon(w);
			m_absItem->SetRandomPosition(m_tiles[t_row][t_col].getPosition());
			m_absItemVector.push_back(m_absItem);
			m_tiles[t_row][t_col].ToggleTileOccupied();
			m_tilesWithItems.push_back(sf::Vector2i(t_row,t_col));
			break;

		case 2:
			m_itemfactory = new ArmourFactory();

			n = rand() % 3;

			a = static_cast<Armours>(n);

			m_absItem = m_itemfactory->CreateArmour(a);
			m_absItem->SetRandomPosition(m_tiles[t_row][t_col].getPosition());
			m_absItemVector.push_back(m_absItem);
			m_tiles[t_row][t_col].ToggleTileOccupied();
			m_tilesWithItems.push_back(sf::Vector2i(t_row, t_col));
			break;

		case 3:
			m_itemfactory = new PotionFactory();

			n = rand() % 3;

			p = static_cast<Potions>(n);

			m_absItem = m_itemfactory->CreatePotion(p);
			m_absItem->SetRandomPosition(m_tiles[t_row][t_col].getPosition());
			m_absItemVector.push_back(m_absItem);
			m_tiles[t_row][t_col].ToggleTileOccupied();
			m_tilesWithItems.push_back(sf::Vector2i(t_row, t_col));
			break;

		default:
			break;
		}
	}
	
}

void Room::SearchTiles()
{

	for (int i = 0; i < 100; i++)
	{
		int randomRow = rand() % 70;
		int randomCol = rand() % 60;

		if (m_tiles[randomRow][randomCol].getType() == TileType::GROUND)
		{
			SpawnItems(randomRow, randomCol);
		}
	}
}

void Room::ComparePlayerAndItem(sf::Vector2i t_playerGridPos, int t_playerRoomID)
{
	if (t_playerRoomID == id)
	{
		for (sf::Vector2i tile : m_tilesWithItems)
		{
			if (t_playerGridPos == tile)
			{
				m_tiles[tile.x][tile.y].ToggleTileOccupied();
				std::cout << "You picked up an item" << std::endl;
			}
		}
	}
}


