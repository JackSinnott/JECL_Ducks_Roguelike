#ifndef ROOM_H
#define ROOM_H

#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <array>
#include "Tile.h"
#include <iostream>

#include "AbstractItemFactory.h"
#include "WeaponFactory.h"
#include "ArmourFactory.h"
#include "PotionFactory.h"
class Room
{
public:
	Room(int t_id, sf::Vector2f t_roomPos);
	~Room();

	void update(sf::Time t_dt, int row, int col);
	void draw(sf::RenderTarget& t_target, sf::RenderStates const t_state = sf::RenderStates::Default)const;

	void CheckPlayer(int t_playerRoomID);
	void setUpTiles(TileType t_type, int row, int col);
	inline int getID() { return id; }

	inline sf::Vector2f getPosition() { return m_pos; }

	inline std::vector<sf::Vector2i> getWalls() { return m_walls; };

	void setGridPosition();

	inline sf::Vector2i getGridPosition() { return sf::Vector2i(row, col); }

	void SpawnItems(int t_row, int t_col);

	void SearchTiles();
private:
	sf::Vector2f m_pos;

	std::shared_ptr<sf::Texture> m_pTexture;
	std::array<std::array<Tile, G_MAP_COLS>,G_MAP_ROWS> m_tiles;
	std::vector<sf::Vector2i> m_walls;
	int row, col;
	int id;

	AbstractItemFactory* m_itemfactory; // Uses a factory method that allows the generation of items
	AbstractItem* m_absItem; // The item itself that can be used to assigned the generated item
	std::vector<AbstractItem*> m_absItemVector; // A vector of items used to store what item is created

	bool m_revealed;
};

#endif // !ROOM_H


