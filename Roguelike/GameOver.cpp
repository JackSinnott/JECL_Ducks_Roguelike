#include "GameOver.h"

/// <summary>
/// The default constructor.
/// </summary>
GameOver::GameOver()
{
	sf::Vector2f buttonSize = sf::Vector2f(600, 100);
	m_backButton = new Button(sf::Vector2f((G_VIEW_WIDTH - buttonSize.x) / 2, G_VIEW_HEIGTH - (buttonSize.y + 100)),
		buttonSize, "BACK TO MAIN MENU", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);

	m_loseText.setFont(g_font);
	m_loseText.setString("You Died");
	m_loseText.setCharacterSize(90);
	m_loseText.setFillColor(sf::Color::White);
	m_loseText.setPosition(G_VIEW_WIDTH / 2, G_VIEW_HEIGTH / 2);
	m_loseText.setOrigin(m_loseText.getLocalBounds().width / 2.0f, m_loseText.getLocalBounds().height / 2.0f);
}

/// <summary>
/// Handles any events the player has triggered while on the GameOver Screen.
/// </summary>
/// <param name="t_event">The SFML event.</param>
void GameOver::processEvents(sf::Event t_event)
{
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			m_backButton->onMouseDown();
		}
	}
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			if (m_backButton->onMouseUp())
			{
				g_gamestate = Gamestate::MainMenu;
			}
		}
	}
}

/// <summary>
/// Updates the back Button.
/// </summary>
/// <param name="t_mousePos">The mouse's position on the screen.</param>
void GameOver::update(sf::Vector2i t_mousePos)
{
	m_backButton->update(t_mousePos);
}

/// <summary>
/// Draws all what's happening on the game over screen.
/// </summary>
/// <param name="t_window">The screen to draw to.</param>
void GameOver::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_loseText);
	m_backButton->render(t_window);
	t_window.setView(t_window.getDefaultView());
}
