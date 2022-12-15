#include "Game.h"
std::unordered_map<std::string, std::shared_ptr<sf::Texture>> TextureManager::texturePtrs; // Singletons need declaring
std::unordered_map<std::string, std::shared_ptr<Audio>> AudioManager::m_sounds;

/// <summary>
/// Class's Default Constructor.
/// </summary>
Game::Game() :

	m_window{ sf::VideoMode{ G_VIEW_WIDTH, G_VIEW_HEIGTH, 32U }, "Roguelike" }
{
	AudioManager::AddSound("ASSETS/Sounds/Menu_Theme.ogg", "Menu_Theme", AudioType::MUSIC);
	AudioManager::AddSound("ASSETS/Sounds/Game_Background.ogg", "Game_Theme", AudioType::MUSIC);
	AudioManager::AddSound("ASSETS/Sounds/Footsteps.wav", "Footstep", AudioType::SFX);
}

//****************************************************************
/// <summary>
/// Class's Default deconstructor.
/// </summary>
Game::~Game(){}

//****************************************************************
/// <summary>
/// The game loop function. Calls upon event handlers, updates, and renders every frame.
/// Once this method ends, so does the game.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			Update(timePerFrame); //60 fps
		}
		Render(m_window); // as many as possible
	}
}

//****************************************************************
/// <summary>
/// Handles ALL events that happen when the player interacts with the game. This includes moving the mouse, clicking on the screen,
/// and pressing buttons.
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			g_exitGame = true;
		}

		switch (g_gamestate)
		{
		case Gamestate::MainMenu:
			AudioManager::Play("Menu_Theme");
			m_mainMenuScreen.processEvents(newEvent);
			break;
		case Gamestate::PauseMenu:
			m_pauseScreen.processEvents(newEvent);
			break;
		case Gamestate::Options:
			m_optionScreen.processEvents(newEvent);
			break;
		case Gamestate::Gameplay:
			AudioManager::Stop("Menu_Theme");
			AudioManager::Play("Game_Theme");
			m_gameScreen.processEvents(newEvent);
			break;
		case Gamestate::GameOver:
			m_gameOverScreen.processEvents(newEvent);
			break;
		case Gamestate::Help:
			m_helpScreen.processEvents(newEvent);
			break;
		default:
			break;
		}


		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}

		if (g_exitGame)
		{
			m_window.close();
		}
	}
}

//****************************************************************
/// <summary>
/// Handles events that happen when the player presses a key on the keyboard,
/// and are not bound to a certain screen - hitting escape to close the window, for instance.
/// </summary>
/// <param name="t_event">The SFML event.</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		g_exitGame = true;
	}
}

//****************************************************************
/// <summary>
/// Method that controls what gets updated, depending on what screen the user is on.
/// </summary>
/// <param name="t_dt">The time that has passed since the last frame.</param>
void Game::Update(sf::Time t_dt)
{
	g_previousState = g_gamestate;

	switch (g_gamestate)
	{
	case Gamestate::MainMenu:
		m_mainMenuScreen.update(sf::Mouse::getPosition(m_window));
		break;
	case Gamestate::PauseMenu:
		m_pauseScreen.update(sf::Mouse::getPosition(m_window));
		break;
	case Gamestate::Options:
		m_optionScreen.update(sf::Mouse::getPosition(m_window));
		break;
	case Gamestate::Gameplay:
		m_gameScreen.update(t_dt);
		break;
	case Gamestate::GameOver:
		m_gameOverScreen.update(sf::Mouse::getPosition(m_window));
		break;
	case Gamestate::Help:
		m_helpScreen.update(sf::Mouse::getPosition(m_window));
		break;
	default:
		break;
	}

	if (g_previousState == Gamestate::Gameplay && (g_gamestate == Gamestate::GameOver || g_gamestate == Gamestate::MainMenu))
	{
		m_gameScreen.ResetGame();
	}
}

//****************************************************************
/// <summary>
/// Method that controls what gets drawn onto the SFML window.
/// </summary>
/// <param name="t_window">The window to draw everything to.</param>
void Game::Render(sf::RenderWindow& t_window)
{
	t_window.clear();
	switch (g_gamestate)
	{
	case Gamestate::MainMenu:
		m_mainMenuScreen.render(t_window);
		break;
	case Gamestate::PauseMenu:
		m_pauseScreen.render(t_window);
		break;
	case Gamestate::Options:
		m_optionScreen.render(t_window);
		break;
	case Gamestate::Gameplay:
		m_gameScreen.render(t_window);
		break;
	case Gamestate::GameOver:
		m_gameOverScreen.render(t_window);
		break;
	case Gamestate::Help:
		m_helpScreen.render(t_window);
		break;
	default:
		break;
	}
	t_window.display();
}
