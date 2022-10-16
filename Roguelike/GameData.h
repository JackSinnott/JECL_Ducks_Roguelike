#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <SFML/graphics.hpp>
#include "TextureManager.h"
#include "Tile.h"
#include <array>
#include <iostream>

class GameData : public sf::Drawable
{
public:
	GameData();

	std::array<std::array<Tile, 20>, 25>& getData() { return m_data; };

	void setTile(int row, int col, CellType t_type);

	void addWalls(std::vector<sf::Sprite*>&);

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const override;
private:
	std::shared_ptr<sf::Texture> m_pTexture;
	static const int s_GAME_WIDTH{ 25 };
	static const int s_GAME_HEIGHT{ 20 };
	std::array<std::array<Tile, 20>, 25> m_data;
};

#endif // !GAME_DATA_H
