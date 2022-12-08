#include "Gameplay.h"

Gameplay::Gameplay() :
	m_grid(0,0)
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
	m_grid.update(t_dt);
	player.Update(t_dt);
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


	for(AbstractItem * n : m_absItemVector)
	{
		n->draw(t_window);
	}
}

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

void Gameplay::MouseEvents(sf::Event t_event)
{
	m_mouseCoordinate.setString("Mouse Position: " + std::to_string(m_mousePositionView.x) + " | " + std::to_string(m_mousePositionView.y));
}


void Gameplay::LoadLevel()
{
	m_levelLoader->Load(0);
	m_levelLoader->Load(1);
	m_levelLoader->Load(2);
	m_levelLoader->Load(3);

	//m_levelData.addWalls(m_walls);
}

void Gameplay::processTurn()
{
	m_testEnemy->update();
}