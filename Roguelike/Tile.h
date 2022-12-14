#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <cstdlib>
#include "Globals.h"
#include <iostream>

class Tile : public sf::Drawable
{
public:
	Tile();

	void setup(std::shared_ptr<sf::Texture>& t_tex,
		sf::Vector2f t_pos, sf::Vector2f t_offset, TileType t_type);

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const override;

	TileType getType() { return m_currentType; }

	sf::Sprite& getSprite() { return m_tile; }

	sf::Vector2f getPosition() { return getSprite().getPosition(); }

	void setGridPosition();

	inline sf::Vector2i getGridPosition() { return sf::Vector2i(row, col); }

	bool TileOccupied();
	void ToggleTileOccupied();
private:
	sf::Sprite m_tile;
	int row, col;
	TileType m_currentType;
	static std::unordered_map<TileType, sf::IntRect> m_rects;
	bool m_hasItem;
};
#endif // !TILE_H