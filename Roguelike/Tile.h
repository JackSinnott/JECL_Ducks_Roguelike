#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <cstdlib>
#include "Grid.h"

enum class CellType
{
	UNUSED = 0,
	GROUND = 1,
	VERTICAL_WALL = 2,
	HORIZONTAL_WALL = 3,
	UPPER_CORNER = 4,
	LOWER_CORNER = 5,
	INSIDE_WALL = 6
};

class Tile : public sf::Drawable
{
public:
	Tile();

	void setup(std::shared_ptr<sf::Texture>& t_tex, sf::Vector2f t_pos, CellType t_type);

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const override;

	CellType getType() { return m_currentType; }

	sf::Sprite& getSprite() { return m_tile; }



private:
	sf::Sprite m_tile;
	CellType m_currentType;
	static std::unordered_map<CellType, sf::IntRect> m_rects;
	Grid m_grid;
};
#endif // !TILE_H