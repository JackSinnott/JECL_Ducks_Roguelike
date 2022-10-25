
/// <summary>
///	Authors:
/// Jack
/// Eoin
/// Caroline
///	Leo
/// Start Date: 13/10/2022
///
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "FileLoader.h"
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Grid.h"

/// <summary>
/// Game Class. Keeps track of Game Flow.
/// </summary>

class Game
{
public:
	Game(sf::Font& t_font);
	Game();
	~Game();

	void run();

private:
	void LoadLevel(int t_level);

	void processEvents();

	void processKeys(sf::Event t_event);

	void Update(sf::Time t_dt);

	void Render(sf::RenderWindow& t_window);

	sf::RenderWindow m_window; // main SFML window
	sf::Text m_infoText;
	sf::Texture m_tileTexture;
	GameData m_levelData;
	LevelLoader* m_levelLoader;
	std::shared_ptr<sf::Texture> m_buttonTexture;
	std::vector<sf::Sprite*> m_walls; // a vector to hold the walls

	bool m_exitGame; // control exiting game

	Player player;
	Weapon m_genericWeapon;
	Enemy* m_testEnemy;
};

#endif // !GAME_HPP

