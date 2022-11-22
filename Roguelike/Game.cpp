#include "Game.h"
std::unordered_map<std::string, std::shared_ptr<sf::Texture>> TextureManager::texturePtrs; // Singletons need declaring

<<<<<<< HEAD
=======
//Game::Game(sf::Font& t_font) :
//	m_window{ sf::VideoMode{ G_VIEW_WIDTH, G_VIEW_HEIGTH, 32U }, "Roguelike" },
//	m_exitGame{ false }, //when true game will exit
//	m_genericWeapon(Weapons::Axe,"Items/Weapons/Axe.png", sf::Vector2f(10, 10), 2)
//{
//	m_levelLoader = new FileLoader(m_levelData);
//
//	LoadLevel(1);
//
//}

//****************************************************************

>>>>>>> d04c390f05285c41c298e6d6e0f1b73dbee78a11
/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
<<<<<<< HEAD
	m_window{ sf::VideoMode{ G_VIEW_WIDTH, G_VIEW_HEIGTH,  32U }, "Roguelike Game" },
	m_exitGame{ false } //when true game will exit
=======
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "Roguelike Game" },
	m_exitGame{ false } //when true game will exit
	//m_genericWeapon(Weapons::Axe,"Items/Weapons/Axe.png", sf::Vector2f(5, 5), 2)
>>>>>>> d04c390f05285c41c298e6d6e0f1b73dbee78a11
{

<<<<<<< HEAD
=======
	LoadLevel(1);

	m_testEnemy = new Enemy(EnemyType::Bat, 100.0f, 100.0f);

	//exampleWeapon = new WeaponFactory();
	exampleItem = new WeaponFactory();
	GenerateRandomItem(*exampleItem);



	//m_testWeapon = new Weapon();
	
>>>>>>> d04c390f05285c41c298e6d6e0f1b73dbee78a11
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

<<<<<<< HEAD
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
=======
>>>>>>> d04c390f05285c41c298e6d6e0f1b73dbee78a11

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
<<<<<<< HEAD
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

=======
	t_window.clear();
	t_window.draw(m_levelData);
	t_window.draw(m_infoText);
	player.Render(m_window);


	for (AbstractWeapon* n: m_absWeaponVector)
	{
		n->draw(m_window);
	}
	m_testEnemy->render(m_window);
	t_window.display();

}

void Game::GenerateRandomItem(AbstractItemFactory &t_factory)
{
	srand(time(0)); 

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;

		std::cout << n << std::endl;

		Weapons w = static_cast<Weapons>(n);

		m_absWeapon = t_factory.CreateWeapon(w);
		m_absWeapon->GenerateRandomPosition();
		m_absWeaponVector.push_back(m_absWeapon);
	}

}

//****************************************************************

void Game::LoadLevel(int t_level)
{
	m_levelLoader->Load(t_level);

	m_levelData.addWalls(m_walls);
}
>>>>>>> d04c390f05285c41c298e6d6e0f1b73dbee78a11
