#include "Player.h"
#include "Globals.h"

/// <summary>
/// Moves the player one grid space along the direction provided by the user's button press.
/// </summary>
/// <param name="t_direction">The direction the player should move.</param>
void Player::MoveSquare(sf::Vector2f t_direction)
{
	m_playerBody.move(t_direction * float(G_CELL_SIZE));
}


/// <summary>
/// Default Constructor of Player.
/// </summary>
Player::Player() : m_playerTexture(nullptr)
{
	m_playerBody.setFillColor(sf::Color::Green);
	m_playerBody.setSize(sf::Vector2f(G_CELL_SIZE, G_CELL_SIZE));

	m_playerBody.setOrigin(G_CELL_SIZE / 2.0f, G_CELL_SIZE / 2.0f);

	// Sets player to centre of map
	m_playerBody.setPosition(G_CELL_SIZE * (G_MAP_ROWS / 2) + G_CELL_SIZE / 2.0f,
		G_CELL_SIZE * (G_MAP_COLS / 2) + G_CELL_SIZE / 2.0f);
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

}

/// <summary>
/// Controls button presses that relate to player movement.
/// For example, if the player presses Up/Down/Left/Right, move player in appropriate direction.
/// </summary>
/// <param name="t_event">Event of button being pressed OR released.</param>
void Player::ProcessKeys(sf::Event t_event)
{
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
				MoveSquare(sf::Vector2f(-1, 0));
				break;

			case sf::Keyboard::W:
			case sf::Keyboard::Up:
				MoveSquare(sf::Vector2f(0, -1));
				break;

			case sf::Keyboard::D:
			case sf::Keyboard::Right:
				MoveSquare(sf::Vector2f(1, 0));
				break;

			case sf::Keyboard::S:
			case sf::Keyboard::Down:
				MoveSquare(sf::Vector2f(0, 1));
				break;

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
