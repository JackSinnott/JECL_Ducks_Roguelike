#include "Gameplay.h"

/// <summary>
/// The class's default constructor.
/// </summary>
Gameplay::Gameplay() :
	player(5,5)
{
	m_levelLoader = new FileLoader(m_grid);

	LoadLevel();
	GenerateRandomItem();
	if (!m_arialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	//Debug mouse coordinates
	m_mouseCoordinate.setFont(m_arialBlackfont);
	m_mouseCoordinate.setPosition(10.0f, 40.0f);
	m_mouseCoordinate.setCharacterSize(20U);
	m_mouseCoordinate.setFillColor(sf::Color::White);
	m_mouseCoordinate.setOutlineThickness(3.0f);
	m_mouseCoordinate.setString("Mouse Position: blank, blank");

	m_enemies.push_back(new Bat(100.0f, 100.0f));
	m_enemies.push_back(new Rat(150.0f, 150.0f));

	m_debugTools = false;
}

/// <summary>
/// Handles any events the player has triggered while on the Gameplay Screen.
/// </summary>
/// <param name="t_event">The SFML event.</param>
void Gameplay::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type ||
		sf::Event::KeyReleased == t_event.type) //user pressed OR released a key
	{
		if (player.ProcessKeys(t_event))
		{
			processTurn();
		}

		if (sf::Event::KeyReleased == t_event.type)
		{
			if (t_event.key.code == sf::Keyboard::P)
			{
				g_gamestate = Gamestate::PauseMenu;
			}
      
			if (t_event.key.code == sf::Keyboard::M)
			{
				m_debugTools = !m_debugTools;
			}
		}
	}

	if (sf::Event::MouseMoved && m_debugTools == true)
	{
		MouseEvents(t_event);
	}

}

/// <summary>
/// Updates the Player, Grid and Enemy objects, every frame.
/// </summary>
/// <param name="t_dt">The passed since the last update call.</param>
void Gameplay::update(sf::Time t_dt)
{
	TextureManager::Collectgarbage();
	player.Update(t_dt);
	m_grid.update(t_dt, player);
	m_grid.whatRoomIsPlayerIn(player.getPlayerPositionInGrid());

}

/// <summary>
/// Draws all what's happening on the gameplay screen.
/// </summary>
/// <param name="t_window">The screen to draw the gameplay to.</param>
void Gameplay::render(sf::RenderWindow& t_window)
{
	t_window.clear();
	m_grid.draw(t_window);
	t_window.draw(m_infoText);
	player.Render(t_window);
	for (Enemy* enemy : m_enemies)
	{
		enemy->render(t_window);
	}
	m_mousePositionView = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));
	if (m_debugTools)
	{
		t_window.draw(m_mouseCoordinate);
	}


	for(AbstractItem * n : m_absItemVector)
	{
		n->draw(t_window);
	}
}

/// <summary>
/// Generates a random item, and gives it to the player. This is the player's starting equipment.
/// </summary>
void Gameplay::GenerateRandomItem()
{
	srand(time(0));

	m_itemfactory = new WeaponFactory();

	//AbstractWeapon* absWeapom;

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;

		Weapons w = static_cast<Weapons>(n);

		m_absItem = m_itemfactory->CreateWeapon(w);
		m_absItem->GenerateRandomPosition();
		m_absItemVector.push_back(m_absItem);

	}
	//absWeapom = m_absItem;
	player.PickUpItem(*m_absItem);
	m_itemfactory = new ArmourFactory();

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;


		Armours a = static_cast<Armours>(n);

		m_absItem = m_itemfactory->CreateArmour(a);
		m_absItem->GenerateRandomPosition();
		m_absItemVector.push_back(m_absItem);
	}
	player.PickUpItem(*m_absItem);
	m_itemfactory = new PotionFactory();

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;

		Potions p = static_cast<Potions>(n);

		m_absItem = m_itemfactory->CreatePotion(p);
		m_absItem->GenerateRandomPosition();
		m_absItemVector.push_back(m_absItem);
	}

	player.PickUpItem(*m_absItem);
}

/// <summary>
/// Handles the mouse events of the game, like the mouse moving around.
/// </summary>
/// <param name="t_event">The event of the mouse doing something.</param>
void Gameplay::MouseEvents(sf::Event t_event)
{
	m_mouseCoordinate.setString("Mouse Position: " + std::to_string(m_mousePositionView.x) + " | " + std::to_string(m_mousePositionView.y));
}

/// <summary>
/// Sets the game back to how it was when it first loaded. Used for when the player dies or exits the game.
/// </summary>
void Gameplay::ResetGame()
{
	// Enemies get regenerated here
	player.reset();

	LoadLevel();
	GenerateRandomItem();
}

/// <summary>
/// Loads the floor the Player is on, with several types of rooms.
/// </summary>
void Gameplay::LoadLevel()
{
	m_levelLoader->Load(0);
	m_levelLoader->Load(1);
	m_levelLoader->Load(2);
	m_levelLoader->Load(3);

	m_grid.setUpWalls();
}

/// <summary>
/// Let's all the Enemy objects process their turns.
/// </summary>
void Gameplay::processTurn()
{
	for (Enemy* enemy : m_enemies)
	{
		m_grid.checkCollisionEnemyWall(*enemy, m_grid.whatRoomIsTargetIn(enemy->getEnemyPositionInGrid()));
		enemy->update(m_grid.getPlayerPos(player), m_grid.getPlayerRoom(), m_grid.whatRoomIsTargetIn(enemy->getEnemyPositionInGrid()));
	}
	
}