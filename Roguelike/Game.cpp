#include "Game.h"
std::unordered_map<std::string, std::shared_ptr<sf::Texture>> TextureManager::texturePtrs; // Singletons need declaring


/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ G_VIEW_WIDTH * 3, G_VIEW_HEIGTH * 3,  32U }, "Roguelike Game" },
	m_exitGame{ false } //when true game will exit
{

}

//****************************************************************

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{

}

//****************************************************************
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
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}

		switch (m_gamestate)
		{
		case Gamestate::MainMenu:
			m_mainMenuScreen.processEvents(newEvent);
			break;
		case Gamestate::PauseMenu:
			m_pauseScreen.processEvents(newEvent);
			break;
		case Gamestate::Options:
			m_optionScreen.processEvents(newEvent);
			break;
		case Gamestate::Gameplay:
			m_gameScreen.processEvents(newEvent);
			break;
		case Gamestate::GameOver:
			m_gameOverScreen.processEvents(newEvent);
			break;
		default:
			break;
		}


		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}

		if (m_exitGame)
		{
			m_window.close();
		}
	}
}

//****************************************************************

void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

//****************************************************************

void Game::Update(sf::Time t_dt)
{
	switch (m_gamestate)
	{
	case Gamestate::MainMenu:
		m_mainMenuScreen.update();
		break;
	case Gamestate::PauseMenu:
		m_pauseScreen.update();
		break;
	case Gamestate::Options:
		m_optionScreen.update();
		break;
	case Gamestate::Gameplay:
		m_gameScreen.update();
		break;
	case Gamestate::GameOver:
		m_gameOverScreen.update();
		break;
	default:
		break;
	}
}

//****************************************************************

void Game::Render(sf::RenderWindow& t_window)
{

	switch (m_gamestate)
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
	default:
		break;
	}

}
