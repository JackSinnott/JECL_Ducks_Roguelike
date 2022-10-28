#include "Game.h"
std::unordered_map<std::string, std::shared_ptr<sf::Texture>> TextureManager::texturePtrs; // Singletons need declaring

Game::Game(sf::Font& t_font) :
	m_window{ sf::VideoMode{ G_VIEW_WIDTH, G_VIEW_HEIGTH, 32U }, "Roguelike" },
	m_exitGame{ false }, //when true game will exit
	m_genericWeapon("Items/Weapons/Axe.png", sf::Vector2f(10, 10), 2)
{
	m_levelLoader = new FileLoader(m_levelData);

	LoadLevel(1);

}

//****************************************************************

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_genericWeapon("Items/Weapons/Axe.png", sf::Vector2f(5, 5), 2)
{
	m_levelLoader = new FileLoader(m_levelData);

	LoadLevel(1);

	m_testEnemy = new Enemy(EnemyType::Bat, 100.0f, 100.0f);

	
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

		if (sf::Event::KeyPressed == newEvent.type || 
			sf::Event::KeyReleased == newEvent.type) //user pressed OR released a key
		{
			if (player.ProcessKeys(newEvent))
			{
				processTurn();
			}

			if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
			{
				processKeys(newEvent);
			}
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

void Game::processTurn()
{
	m_testEnemy->update();
}

//****************************************************************

void Game::Update(sf::Time t_dt)
{
	TextureManager::Collectgarbage();

}

//****************************************************************

void Game::Render(sf::RenderWindow& t_window)
{
	t_window.clear();
	t_window.draw(m_levelData);
	t_window.draw(m_infoText);
	player.Render(m_window);
	m_genericWeapon.draw(m_window);
	m_testEnemy->render(m_window);
	t_window.display();

}

void Game::GenerateRandomWeapon()
{
	
}

//****************************************************************

void Game::LoadLevel(int t_level)
{
	m_levelLoader->Load(t_level);

	m_levelData.addWalls(m_walls);
}