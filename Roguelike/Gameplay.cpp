#include "Gameplay.h"

Gameplay::Gameplay() :
	m_grid(0,0)
{
	m_levelLoader = new FileLoader(m_grid);

	LoadLevel();
	GenerateRandomItem();

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


	for(AbstractItem * n : m_absItemVector)
	{
		n->draw(t_window);
	}
}

void Gameplay::GenerateRandomItem()
{
	srand(time(0));

	m_itemfactory = new WeaponFactory();

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;

		Weapons w = static_cast<Weapons>(n);

		m_absItem = m_itemfactory->CreateWeapon(w);
		m_absItem->GenerateRandomPosition();
		m_absItemVector.push_back(m_absItem);
	}

	m_itemfactory = new ArmourFactory();

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;


		Armours a = static_cast<Armours>(n);

		m_absItem = m_itemfactory->CreateArmour(a);
		m_absItem->GenerateRandomPosition();
		m_absItemVector.push_back(m_absItem);
	}

	m_itemfactory = new PotionFactory();

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 3;

		Potions p = static_cast<Potions>(n);

		m_absItem = m_itemfactory->CreatePotion(p);
		m_absItem->GenerateRandomPosition();
		m_absItemVector.push_back(m_absItem);
	}

	//for (AbstractItem * n: m_absItemVector)
	//{
	//	switch (n->GetItemType())
	//	{
	//	case ItemType::Weapon:
	//		//m_testingWeapon = t_item;
	//		std::cout << "This is a weapon" << std::endl;
	//		break;
	//	case ItemType::Armour:
	//		std::cout << "This is some armour" << std::endl;
	//		break;
	//	case ItemType::Potion:
	//		std::cout << "This is a potion" << std::endl;
	//		break;
	//	default:
	//		std::cout << "Unable to get item type" << std::endl;
	//		break;
	//	}
	//}

	player.PickUpItem(*m_absItem);
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
