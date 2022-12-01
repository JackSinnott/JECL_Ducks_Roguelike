#include "Player.h"

std::unordered_map<Armours, sf::IntRect> Player::m_rects = std::unordered_map<Armours, sf::IntRect>(); // initialize
sf::IntRect Player::m_noArmourRect = sf::IntRect();

/// <summary>
/// Move the player by the specified row/col parameter passed into the function 
/// </summary>
/// <param name="row">The row change to move by (if any)</param>
/// <param name="col">The column change to move by (if any)</param>
void Player::move(int row, int col)
{
	m_playerBody.move(sf::Vector2f( row, col ) * float(G_CELL_SIZE));
}

/// <summary>
/// Default Constructor of Player.
/// </summary>
Player::Player() : m_playerTexture(nullptr)
{
	m_playerTexture = TextureManager::Acquire(ITEMS_TEXTURE);
	m_playerBody.setTexture(*m_playerTexture);

	UpdateArmourLook();

	m_playerBody.setOrigin(m_playerBody.getTextureRect().width / 2.0f, 
		m_playerBody.getTextureRect().height / 2.0f);
	m_playerBody.setScale(2.0f, 2.0f);
	// Sets player to centre of map hard coded for now 
	setPosition(int(G_ROOM_ROWS / 2), int(G_ROOM_COLS / 2));
	//setPosition(0, 1);

	if (m_rects.size() == 0)
	{
		//m_rects.try_emplace(Armours)
		m_rects.try_emplace(Armours::Heavy, sf::IntRect{ 16,128,16,16 });
		m_rects.try_emplace(Armours::Medium, sf::IntRect{ 32,128,16,16 });
		m_rects.try_emplace(Armours::Light, sf::IntRect{ 16,112,16,16 });
		m_noArmourRect = sf::IntRect{ 32,176,16,16 };
	}
}




/// <summary>
/// Updates the player object every frame.
/// </summary>
/// <param name="t_deltaTime">Time since last frame.</param>
/// 
/// ### Example:
/// ~~~~~~~~~~~~~~~~~~~~~.cpp
/// playerObject.Update(dt);
/// ~~~~~~~~~~~~~~~~~~~~~
void Player::Update(sf::Time t_deltaTime)
{
	UpdateArmourLook();
}

/// <summary>
/// Controls button presses that relate to player movement.
/// For example, if the player presses Up/Down/Left/Right, move player in appropriate direction.
/// </summary>
/// <param name="t_event">Event of button being pressed OR released.</param>
bool Player::ProcessKeys(sf::Event t_event)
{
	bool action = false;
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (m_pressingButton != t_event.key.code) // only allow movement
			// if the player is pressing a key for the first time
		{
			// Do Player things
			switch (t_event.key.code)
			{
			case sf::Keyboard::A:
			case sf::Keyboard::Left:
				move(-1, 0);
				action = true;
				break;

			case sf::Keyboard::W:
			case sf::Keyboard::Up:
				move(0, -1);
				action = true;
				break;

			case sf::Keyboard::D:
			case sf::Keyboard::Right:
				move(1, 0);
				action = true;
				break;

			case sf::Keyboard::S:
			case sf::Keyboard::Down:
				move(0, 1);
				action = true;
				break;

			case sf::Keyboard::V:
				std::cout << "Player pos: { " << m_playerBody.getPosition().x << ", " << m_playerBody.getPosition().y << " }";
			default:
				break;
			}

			m_pressingButton = t_event.key.code;
		}
	}

	else
	{
		m_pressingButton = sf::Keyboard::Unknown;
	}

	return action;

}

/// <summary>
/// Draws the player to the game screen.
/// </summary>
/// <param name="t_window">The window that the player will be drawn to.</param>
/// ### Example:
/// ~~~~~~~~~~~~~~~~~~~~~.cpp
/// playerObject.draw(gameWindow);
/// ~~~~~~~~~~~~~~~~~~~~~
void Player::Render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerBody);
}

sf::Vector2f Player::GetPosition()
{
	return m_playerBody.getPosition();
}

void Player::setPosition(int row, int col)
{
	// Sets player to centre of map
	m_playerBody.setPosition(G_CELL_SIZE * (row),
		G_CELL_SIZE * (col));
}

void Player::PickUpItem(AbstractItem& t_item)
{
	//When the item is picked up. It will need to go into the right item slot type.
	
	switch (t_item.GetItemType())
	{
	case ItemType::Weapon:
		//m_testingWeapon = t_item;
		m_currentWeapon = &t_item;
		std::cout << "You picked up a weapon" << std::endl;
		break;
	case ItemType::Armour:
		m_currentArmour = &t_item;
		std::cout << "You picked up some armour" << std::endl;
		break;
	case ItemType::Potion:
		m_currentPotion = &t_item;
		std::cout << "You picked up a potion" << std::endl;
		break;
	default:
		std::cout << "Unable to get item type" << std::endl;
		break;
	}
}

int Player::GetWeaponDamage()
{
	
	return 0;
}

int Player::GetArmourClass()
{
	return 0;
}

void Player::UsePotion()
{
}

void Player::UpdateArmourLook()
{
	if (m_currentArmour != nullptr)
	{
		AbstractArmour* currentArmourAbs = static_cast<AbstractArmour*>(m_currentArmour);

		Armours armourType = currentArmourAbs->GetType();
		
		m_playerBody.setTextureRect(m_rects.at(armourType));
	}

	else
	{
		m_playerBody.setTextureRect(m_noArmourRect);
	}
}