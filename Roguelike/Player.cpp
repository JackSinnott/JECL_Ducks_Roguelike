#include "Player.h"

std::unordered_map<Armours, sf::IntRect> Player::m_rects = std::unordered_map<Armours, sf::IntRect>(); // initialize
sf::IntRect Player::m_noArmourRect = sf::IntRect();

/// <summary>
/// Returns the row and column in the Grid the Player currently is.
/// </summary>
/// <returns>The row and column the Player is occupying.</returns>
sf::Vector2i Player::getPlayerPositionInGrid()
{
	return sf::Vector2i(row, col);
}

/// <summary>
/// Sets up the Player's row and column in the Grid.
/// This version does it by calculating it from the Tile size.
/// </summary>
void Player::setPlayerPositionInGrid()
{
	row = m_playerBody.getPosition().x / G_CELL_SIZE;
	col = m_playerBody.getPosition().y / G_CELL_SIZE;
}

/// <summary>
/// Sets up the Player's row and column in the Grid.
/// This version does it by setting it manually.
/// </summary>
/// <param name="t_pos">The manual row and column of the Player in the Grid.</param>
void Player::setPlayerPositionInGrid(sf::Vector2i t_pos)
{
	row = t_pos.x;
	col = t_pos.y;
}

/// <summary>
/// Move the player by the specified row/column parameter passed into the function.
/// </summary>
/// <param name="row">The row change to move by (if any).</param>
/// <param name="col">The column change to move by (if any).</param>
void Player::move(int row, int col)
{
	m_playerBody.move(sf::Vector2f( row, col ) * float(G_CELL_SIZE));
	//CalculateDamageToEnemy(1, 0);
}

/// <summary>
/// Default constructor for Player.
/// </summary>
Player::Player()
{
	CombatSystem::SetPlayerHealth(&m_health);
}

/// <summary>
/// Overloaded constructor for Player, that sets the Player's position.
/// </summary>
/// <param name="t_row">The player's row in the grid.</param>
/// <param name="t_col">The player's column in the grid.</param>
Player::Player(int t_row, int t_col) : m_playerTexture(nullptr),
	row(t_row),
	col(t_col)
{
	m_playerTexture = TextureManager::Acquire(ITEMS_TEXTURE);
	m_playerBody.setTexture(*m_playerTexture);

	UpdateArmourLook();

	m_playerBody.setOrigin(m_playerBody.getTextureRect().width / 2.0f, 
		m_playerBody.getTextureRect().height / 2.0f);
	m_playerBody.setScale(2.0f, 2.0f);

	// Sets player to centre of map hard coded for now 
	setGridPosition(int(G_ROOM_ROWS / 2), int(G_ROOM_COLS / 2));

	m_playerInventory.SetupInventory(m_playerBody.getPosition());
	m_playerView.setCenter(m_playerBody.getPosition());
	m_playerView.setSize(G_VIEW_WIDTH/2, G_VIEW_HEIGTH/2);

	if (m_rects.size() == 0)
	{
		m_rects.try_emplace(Armours::Heavy, sf::IntRect{ 16,128,16,16 });
		m_rects.try_emplace(Armours::Medium, sf::IntRect{ 32,128,16,16 });
		m_rects.try_emplace(Armours::Light, sf::IntRect{ 16,112,16,16 });
		m_noArmourRect = sf::IntRect{ 32,176,16,16 };
	}

	CombatSystem::SetPlayerHealth(&m_health);
}


/// <summary>
/// Updates the player object every frame.
/// </summary>
/// <param name="t_deltaTime">The time since last frame.</param>
/// 
/// ### Example:
/// ~~~~~~~~~~~~~~~~~~~~~.cpp
/// playerObject.Update(dt);
/// ~~~~~~~~~~~~~~~~~~~~~
void Player::Update(sf::Time t_deltaTime)
{
	setPlayerPositionInGrid();
	//std::cout << "Player row: " << row << "player col: " << col << "\n";
	UpdateArmourLook();

	if (m_health <= 0)
	{
		//g_gamestate = Gamestate::GameOver;
	}
}

/// <summary>
/// Resets the Player's health, position and camera back to the start. Used for when the Game is reset.
/// </summary>
void Player::reset()
{
	m_health = m_maxHealth;
	setGridPosition(int(G_ROOM_ROWS / 2), int(G_ROOM_COLS / 2));
	m_playerView.setCenter(m_playerBody.getPosition());
}

/// <summary>
/// Controls button presses that relate to player movement.
/// For example, if the player presses Up/Down/Left/Right, move player in appropriate direction.
/// </summary>
/// <param name="t_event">Event of button being pressed OR released.</param>
/// <returns>Whether the Player does an action.</returns>
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
				if (canWeMoveLeft())
				{
					move(-1, 0);
					action = true;
				}
				break;

			case sf::Keyboard::W:
			case sf::Keyboard::Up:
				if (canWeMoveUp())
				{
					move(0, -1);
					action = true;
				}
				break;

			case sf::Keyboard::D:
			case sf::Keyboard::Right:
				if (canWeMoveRight())
				{
					move(1, 0);
					action = true;
				}
				break;

			case sf::Keyboard::S:
			case sf::Keyboard::Down:
				if (canWeMoveDown())
				{
					move(0, 1);
					action = true;
				}
				break;
			case sf::Keyboard::Space:
				std::cout << GetWeaponDamage() << std::endl;
				break;
			case sf::Keyboard::E:
				UsePotion();
				break;
			case sf::Keyboard::V:
				std::cout << "Player pos: { " << m_playerBody.getPosition().x << ", " << m_playerBody.getPosition().y << " }" << std::endl;
				break;
			case sf::Keyboard::I:
				m_playerInventory.ToggleInventory();
				break;
			case sf::Keyboard::L:
				action = true;
				break;
			default:
				break;
			}

			

			m_pressingButton = t_event.key.code;
			m_playerView.setCenter(m_playerBody.getPosition());
			m_playerInventory.UpdatePosition(m_playerBody.getPosition());
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
	m_playerInventory.Draw(t_window);
	t_window.draw(m_playerBody);
	t_window.setView(m_playerView);
}

/// <summary>
/// returns the player's position on the screen.
/// </summary>
/// <returns>The position of the player.</returns>
sf::Vector2f Player::GetPosition()
{
	return m_playerBody.getPosition();
}

/// <summary>
/// Changes the position of the player, in relation to the grid.
/// (ie 1,2 would put the player in second row, third column, as it starts with 0,0)
/// </summary>
/// <param name="row">The player's new row in the grid.</param>
/// <param name="col">The player's new column in the grid.</param>
void Player::setGridPosition(int row, int col)
{
	// Sets player to centre of map
	m_playerBody.setPosition(G_CELL_SIZE * (row),
		G_CELL_SIZE * (col));
}

/// <summary>
/// Let's the Player pick up an item and store it in their Inventory.
/// </summary>
/// <param name="t_item">The Item that is picked up.</param>
void Player::PickUpItem(AbstractItem& t_item)
{
	//When the item is picked up. It will need to go into the right item slot type.
	m_playerInventory.StoreItem(t_item);
}

/// <summary>
/// Returns the damage the weapon will do with the target.
/// </summary>
/// <returns>The damage this weapon will do.</returns>
int Player::GetWeaponDamage()
{
	return m_playerInventory.GetWeapon().GetDamage();
}

/// <summary>
/// Returns the armour class of the Player.
/// </summary>
/// <returns>The AC of the armour the Player is wearing.</returns>
int Player::GetArmourClass()
{
	return m_playerInventory.GetArmour().GetArmourClass();
}

/// <summary>
/// Uses the #Potions that the player currently has in their Inventory.
/// </summary>
void Player::UsePotion()
{
	if (&m_playerInventory.GetPotion() != nullptr)
	{
		switch (m_playerInventory.GetPotion().GetPotionType())
		{
		case Potions::Health:
			std::cout << "Health before: " << m_health << std::endl;

			m_health += m_playerInventory.GetPotion().UseEffect();

			if (m_health > m_maxHealth)
			{
				m_health = m_maxHealth;
			}
			std::cout << "Health after: " << m_health << std::endl;
			std::cout << "Health Potion used" << std::endl;
			m_playerInventory.RemovePotion();
			break;
		case Potions::Strength:
			m_playerInventory.GetPotion().UseEffect();
			std::cout << "Strength Potion used" << std::endl;
			m_playerInventory.RemovePotion();
			break;
		case Potions::Speed:
			m_playerInventory.GetPotion().UseEffect();
			std::cout << "Speed Potion used" << std::endl;
			m_playerInventory.RemovePotion();
			break;
		};
	}
	else
	{
		std::cout << "You have no potion available" << std::endl;
	}
}

/// <summary>
/// Updates how the Player looks when they pick up some #Armours.
/// </summary>
void Player::UpdateArmourLook()
{
	if (&m_playerInventory.GetArmour() != nullptr)
	{
		AbstractArmour* currentArmourAbs = static_cast<AbstractArmour*>(&m_playerInventory.GetArmour());

		Armours armourType = currentArmourAbs->GetType();
		
		m_playerBody.setTextureRect(m_rects.at(armourType));
	}

	else
	{
		m_playerBody.setTextureRect(m_noArmourRect);
	}
}

/// <summary>
/// Calculates the hit chance the player has on the enemy,
/// and then if they hit, calculates the damage to the enemy and applies it.
/// </summary>
/// <param name="t_EnemyAC">The enemy's armour class, ie. how difficult they are to hit.</param>
/// <param name="t_index">The index of the enemy in the world.</param>
void Player::CalculateDamageToEnemy(int t_EnemyAC, int t_index)
{
	bool hitEnemy = CombatSystem::BattleEquation(level, t_EnemyAC, GetHitModifier());

	if (hitEnemy)
	{
		std::cout << "You hit the enemy!" << std::endl;
		xp += CombatSystem::HurtEnemy(t_index, GetDamageModifier() + GetWeaponDamage());
	}

	else
	{
		std::cout << "You missed the enemy..." << std::endl;
	}
}

/// <summary>
/// Calculates the additional hit chance of the player, based on their strength.
/// </summary>
/// <returns>The additional hit chance the player has when trying to hit the enemy.</returns>
int Player::GetHitModifier()
{
	int modifier = 0;

	if (m_strength < 7)
	{
		modifier = -7 + m_strength;
	}

	else if (m_strength >= 17)
	{
		modifier++;

		if (m_strength >= 19)
		{
			modifier++;

			if (m_strength >= 21)
			{
				modifier++;

				if (m_strength >= 31)
				{
					modifier++;
				}
			}
		}
	}

	return modifier;
}

/// <summary>
/// Calculates the extra damage the player will do, based on their strength.
/// </summary>
/// <returns>The additional damage the player does to the enemy.</returns>
int Player::GetDamageModifier()
{
	int modifier = 0;

	if (m_strength < 7)
	{
		modifier = -7 + m_strength;
	}

	else if (m_strength >= 16)
	{
		modifier++;

		if (m_strength >= 17)
		{
			modifier++;

			if (m_strength >= 18)
			{
				modifier++;

				if (m_strength >= 20)
				{
					modifier++;

					if (m_strength >= 22)
					{
						modifier++;

						if (m_strength >= 31)
						{
							modifier++;
						}
					}
				}
			}
		}
	}

	return modifier;
}
