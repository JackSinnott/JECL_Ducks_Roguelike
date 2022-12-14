#ifndef ROOM_H
#define ROOM_H

#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <array>
#include "Tile.h"
#include <iostream>
class Room
{
public:
	Room(int t_id, sf::Vector2f t_roomPos);
	~Room();

	void update(sf::Time t_dt, int row, int col);
	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;

	void CheckPlayer(int t_playerRoomID);
	void setUpTiles(TileType t_type, int row, int col);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	inline int getID() { return id; }

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	inline sf::Vector2f getPosition() { return m_pos; }

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	inline std::vector<sf::Vector2i> getWalls() { return m_walls; };

	void setGridPosition();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	inline sf::Vector2i getGridPosition() { return sf::Vector2i(row, col); }

private:
	///
	sf::Vector2f m_pos;

	///
	std::shared_ptr<sf::Texture> m_pTexture;

	///
	std::array<std::array<Tile, G_MAP_COLS>,G_MAP_ROWS> m_tiles;

	///
	std::vector<sf::Vector2i> m_walls;

	///
	int row;

	///
	int col;

	///
	int id;

	///
	bool m_revealed;
};

#endif // !ROOM_H


