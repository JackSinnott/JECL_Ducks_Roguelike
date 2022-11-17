#pragma once
#include "Globals.h"
#include "GameData.h"
#include "FileLoader.h"
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Grid.h"

class Gameplay
{
public:
	Gameplay();
	void processEvents(sf::Event t_event);
	void update();
	void render(sf::RenderWindow& t_window);
private:
	void LoadLevel(int t_level);
	void processTurn();

	sf::Text m_infoText;
	sf::Texture m_tileTexture;
	GameData m_levelData;
	LevelLoader* m_levelLoader;
	std::shared_ptr<sf::Texture> m_buttonTexture;
	std::vector<sf::Sprite*> m_walls; // a vector to hold the walls

	Player player;
	Weapon m_genericWeapon;
	Enemy* m_testEnemy;
};
