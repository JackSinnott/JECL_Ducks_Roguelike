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
	srand(time(0));

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

		for (AbstractItem* n : m_absItemVector)
		{
			t_target.draw(n->GetSprite());
		}
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

	if (m_tiles[row][col].getType() != TileType::UNUSED && m_tiles[row][col].getType() != TileType::GROUND)
	{
		m_walls.push_back(m_tiles[row][col].getGridPosition());
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
		sf::Vector2i i = sf::Vector2i(t_row, t_col);

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



			//m_mapWithItems.insert(std::pair<sf::Vector2i, AbstractItem*>(i, m_absItem));

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

void Room::ComparePlayerAndItem(Player t_player, int t_playerRoomID)
{
	if (t_playerRoomID == id)
	{
		//
		std::map<sf::Vector2i, AbstractItem*>::iterator it;

		//for (it = m_mapWithItems.begin(); it != m_mapWithItems.end(); it++)
		//{
		//	if (it->first == t_player.getPlayerPositionInGrid())
		//	{
		//		t_player.PickUpItem(*it->second);
		//		m_mapWithItems.erase(it->first);
		//	}
		//}
	}
}


