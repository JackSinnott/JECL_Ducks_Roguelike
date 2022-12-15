#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <cstdlib>
#include "Globals.h"
#include <iostream>

/// <summary>
/// Tile class, handles everything for one cell of the Grid.
/// </summary>

class Tile : public sf::Drawable
{
public:
	Tile();

	void setup(std::shared_ptr<sf::Texture>& t_tex,
		sf::Vector2f t_pos, sf::Vector2f t_offset, TileType t_type);

	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const override;

	/// <summary>
	/// Returns what type of tile this one is.
	/// </summary>
	/// <returns>The tile type of this Tile object.</returns>
	TileType getType() { return m_currentType; }

	/// <summary>
	/// Returns the Tile's sprite.
	/// </summary>
	/// <returns>The Tile's sprite.</returns>
	sf::Sprite& getSprite() { return m_tile; }

	/// <summary>
	/// Returns the tile's position in the Game.
	/// </summary>
	/// <returns>The Tile's position.</returns>
	sf::Vector2f getPosition() { return getSprite().getPosition(); }

	void setGridPosition();

	/// <summary>
	/// Returns the rows and columns this Tile occupies.
	/// </summary>
	/// <returns>The row and columns that this Tile is in.</returns>
	inline sf::Vector2i getGridPosition() { return sf::Vector2i(row, col); }

	bool TileOccupied();
	void ToggleTileOccupied();
private:

	///The appearance of the Tile.
	sf::Sprite m_tile;

	///What row the Tile is in.
	int row;

	///What column the Tile is in.
	int col;

	///What type this tile is.
	TileType m_currentType;

	/// <summary>
	/// The rects of the sprite, this will change the appearance of the tile depending on its TileType.
	/// </summary>
	static std::unordered_map<TileType, sf::IntRect> m_rects;

	/// Checks if the tile has an item or not
	bool m_hasItem;
};
#endif // !TILE_H