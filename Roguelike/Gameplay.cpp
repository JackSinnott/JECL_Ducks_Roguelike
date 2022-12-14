#include "Gameplay.h"

Gameplay::Gameplay() :
	m_grid(0, 0)
{
	m_itemfactory = new WeaponFactory();
	Weapons w = static_cast<Weapons>(2);
	m_starterWeapon = m_itemfactory->CreateWeapon(w);
	
	player = Player(5,5, m_starterWeapon);
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

	m_testEnemy = new Enemy(EnemyType::Bat, 100.0f, 100.0f);

	m_debugTools = false;
}

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

void Gameplay::update(sf::Time t_dt)
{
	TextureManager::Collectgarbage();
	player.Update(t_dt);
	m_grid.update(t_dt, player);
	m_grid.whatRoomIsPlayerIn(player.getPlayerPositionInGrid());

}

void Gameplay::render(sf::RenderWindow& t_window)
{
	t_window.clear();
	m_grid.draw(t_window);
	t_window.draw(m_infoText);
	player.Render(t_window);
	m_testEnemy->render(t_window);
	m_mousePositionView = t_window.mapPixelToCoords(sf::Mouse::getPosition(t_window));
	if (m_debugTools)
	{
		t_window.draw(m_mouseCoordinate);
	}


	//for(AbstractItem * n : m_absItemVector)
	//{
	//	n->draw(t_window);
	//}
}

void Gameplay::GenerateRandomItem()
{
	for (int i = 0; i < 4; i++)
	{
		m_grid.GetRooms()[i]->SearchTiles();
	}
}

void Gameplay::MouseEvents(sf::Event t_event)
{
	m_mouseCoordinate.setString("Mouse Position: " + std::to_string(m_mousePositionView.x) + " | " + std::to_string(m_mousePositionView.y));
}

void Gameplay::ResetGame()
{
	// Enemies get regenerated here
	player.reset();

	LoadLevel();
	GenerateRandomItem();
}


void Gameplay::LoadLevel()
{
	m_levelLoader->Load(0);
	m_levelLoader->Load(1);
	m_levelLoader->Load(2);
	m_levelLoader->Load(3);

	m_grid.setUpWalls();
}

void Gameplay::processTurn()
{
	m_testEnemy->update();
}