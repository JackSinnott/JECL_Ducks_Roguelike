#include "Gameplay.h"

Gameplay::Gameplay() :
	m_grid(0,0)
{
	m_levelLoader = new FileLoader(m_grid);

	LoadLevel();
	exampleItem = new WeaponFactory();
	GenerateRandomItem(*exampleItem);
	m_testEnemy = new Enemy(EnemyType::Bat, 100.0f, 100.0f);
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
	}
}

void Gameplay::update()
{
	TextureManager::Collectgarbage();
}

void Gameplay::render(sf::RenderWindow& t_window)
{
	t_window.clear();
	m_grid.draw(t_window);
	t_window.draw(m_infoText);
	player.Render(t_window);
	m_testEnemy->render(t_window);

	for(AbstractWeapon * n : m_absWeaponVector)
	{
		n->draw(t_window);
	}

	t_window.display();
}

void Gameplay::GenerateRandomItem(AbstractItemFactory& t_factory)
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


void Gameplay::LoadLevel()
{
	m_levelLoader->Load();
	m_levelLoader->Load();

	//m_levelData.addWalls(m_walls);
}

void Gameplay::processTurn()
{
	m_testEnemy->update();
}
