
//	Authors:
// Jack
// Eoin
// Caroline
// Leo
// Start Date: 13/10/2022

#ifndef GAME_HPP
#define GAME_HPP

#include <time.h>
#include "Globals.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "PauseMenu.h"
#include "GameOver.h"
#include "Options.h"
#include "Help.h"
#include "AudioManager.h"

/// <summary>
/// The game class. Keeps track of Game Flow.
/// </summary>

class Game
{
public:

	//Game(sf::Font& t_font);
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);

	void Update(sf::Time t_dt);

	void Render(sf::RenderWindow& t_window);

	///Instance of the gameplay screen.
	Gameplay m_gameScreen;

	///Instance of the main menu screen.
	MainMenu m_mainMenuScreen;

	///Instance of the pause screen.
	PauseMenu m_pauseScreen;

	///Instance of the game over screen.
	GameOver m_gameOverScreen;

	///Instance of the options screen.
	Options m_optionScreen;

	///Instance of the help screen.
	Help m_helpScreen;

	///The main SFML window.
	sf::RenderWindow m_window; 
};

#endif // !GAME_HPP

