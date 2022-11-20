#ifndef GAME_DATA_H
#define GAME_DATA_H

#include "TextureManager.h"
#include "Tile.h"
#include <array>
#include <iostream>
#include "Globals.h"
#include <string>
#include "Player.h"

class GameData : public sf::Drawable
{
public:
	//GameData(int t_index);
	GameData();

	//std::array<std::array<Tile, G_MAP_COLS>, G_MAP_ROWS>& getData() { return m_data; };

	void setTile(int row, int col, CellType t_type, int t_roomPlacement);

	void addWalls(std::vector<sf::Sprite*>& t_walls);

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const override;

	void GenerateFloor();
private:
	std::shared_ptr<sf::Texture> m_pTexture;
	static const int s_GAME_WIDTH{ G_MAP_ROWS };
	static const int s_GAME_HEIGHT{ G_MAP_COLS };
	std::array<std::array<std::array<Tile, G_MAP_COLS>, G_MAP_ROWS>, 9>* m_data;

	sf::Vector2f addedDistance;
};

#endif // !GAME_DATA_H
