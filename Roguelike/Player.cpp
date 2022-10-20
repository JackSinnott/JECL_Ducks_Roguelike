#include "Player.h"

/// <summary>
/// Default Constructor of Player.
/// </summary>
Player::Player() : m_playerTexture(nullptr)
{
	m_playerBody.setFillColor(sf::Color::Green);
	m_playerBody.setSize(sf::Vector2f(100,100));
	m_playerBody.setPosition(100,100);
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
