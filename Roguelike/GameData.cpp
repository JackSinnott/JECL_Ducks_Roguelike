#include "GameData.h"

//GameData::GameData(int t_index)
//{
	//int row = t_index % 3;
	//int col = t_index / 3;

	//addedDistance = sf::Vector2f(G_CELL_SIZE * G_MAP_ROWS * row,
	//	G_CELL_SIZE * G_MAP_COLS * col);

//
//
//	m_pTexture = TextureManager::Acquire("ASSETS//IMAGES//Level//MapTiles.png");
//}

//********************************************************

GameData::GameData()
{
	m_data = new std::array<std::array<std::array<Tile, G_MAP_COLS>, G_MAP_ROWS>, 9>;
	m_pTexture = TextureManager::Acquire("ASSETS//IMAGES//Level//MapTiles.png");
}

//********************************************************

void GameData::setTile(int row, int col, CellType t_type,int t_roomPlacement)
{
	int n_row = t_roomPlacement % 3;
	int n_col = t_roomPlacement / 3;

	addedDistance = sf::Vector2f(G_CELL_SIZE * G_MAP_ROWS * n_row,
		G_CELL_SIZE * G_MAP_COLS * n_col);


	(*m_data)[t_roomPlacement][row][col].setup(m_pTexture,
		sf::Vector2f{ static_cast<float>(row * G_CELL_SIZE) +
		addedDistance.x,static_cast<float>(col * G_CELL_SIZE) + addedDistance.y}, 
		((G_MAP_ROWS * G_CELL_SIZE) / 2.0f) + addedDistance.x + 16.0f, t_type);
}

//********************************************************

void GameData::addWalls(std::vector<sf::Sprite*>& t_walls)
{
	for (auto& room : (*m_data))
		for (auto& x : room)
			for (auto& tile : x)
				if (tile.getType() != CellType::GROUND && tile.getType() != CellType::UNUSED)
					t_walls.push_back(&tile.getSprite());
}

//********************************************************

void GameData::draw(sf::RenderTarget& t_target, sf::RenderStates const t_state) const
{
	for (auto& room : (*m_data))
		for (auto& row : room)
			for (auto& x : row)
				t_target.draw(x, t_state);
}

void GameData::GenerateFloor()
{

}
