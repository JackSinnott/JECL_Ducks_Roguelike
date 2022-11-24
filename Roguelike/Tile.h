#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <cstdlib>
#include "Globals.h"

class Tile : public sf::Drawable
{
public:
	Tile();

	void setup(std::shared_ptr<sf::Texture>& t_tex,
		sf::Vector2f t_pos, TileType t_type);

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const override;

	TileType getType() { return m_currentType; }

	sf::Sprite& getSprite() { return m_tile; }



private:
	sf::Sprite m_tile;
	TileType m_currentType;
	static std::unordered_map<TileType, sf::IntRect> m_rects;
};
#endif // !TILE_H