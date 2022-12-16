#ifndef ROOM_H
#define ROOM_H

#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <array>
#include "Tile.h"
#include <iostream>

/// <summary>
/// Class that handles Tile objects, and organises them together to look and act coherant.
/// Also is used to seperate itself from other Rooms.
/// </summary>

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
	/// Returns the Room's ID.
	/// </summary>
	/// <returns>The Room's ID.</returns>
	inline int getID() { return id; }

	/// <summary>
	/// Gets the start position of the Room in relation to the whole Grid. 
	/// </summary>
	/// <returns>The position of the Room.</returns>
	inline sf::Vector2f getPosition() { return m_pos; }

	/// <summary>
	/// Get all the positions of the Tiles that are #VERTICAL_WALL,
	/// #HORIZONTAL_WALL, or #INSIDE_WALL.
	/// </summary>
	/// <returns>All the positions of the walls.</returns>
	inline std::vector<sf::Vector2i> getWalls() { return m_walls; };

	void setGridPosition();

	/// <summary>
	///Gets the row and column of this Room occupies in the Grid.
	/// </summary>
	/// <returns>The row and column of this Room.</returns>
	inline sf::Vector2i getGridPosition() { return sf::Vector2i(row, col); }

private:
	///The position of the Room.
	sf::Vector2f m_pos;

	///The shared pointer to the texture of the Tile objects.
	std::shared_ptr<sf::Texture> m_pTexture;

	///The tiles themselves, laid out in a 2D array.
	std::array<std::array<Tile, G_MAP_COLS>,G_MAP_ROWS> m_tiles;

	///All the positions of the Tiles that are #VERTICAL_WALL,
	/// #HORIZONTAL_WALL, or #INSIDE_WALL.
	std::vector<sf::Vector2i> m_walls;

	///The row the Room is in on the Grid - All rooms are in a 3x3 layout together.
	int row;

	///The column the Room is in on the Grid - All rooms are in a 3x3 layout together.
	int col;

	///an ID for the Room - used for identification, like what room Player entered.
	int id;

	///Whether the Room has been visited by the Player, and should be drawn.
	bool m_revealed;
};

#endif // !ROOM_H


