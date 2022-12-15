#include "Options.h"

/// <summary>
/// The default constructor.
/// </summary>
Options::Options()
{
	sf::Vector2f buttonSize = sf::Vector2f(250, 100);
	m_backButton = new Button(sf::Vector2f(G_VIEW_WIDTH - (buttonSize.x + 20), G_VIEW_HEIGTH - (buttonSize.y + 20)),
		buttonSize, "BACK", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);
}

/// <summary>
/// Handles any events the player has triggered while on the Options Screen.
/// </summary>
/// <param name="t_event">The SFML event.</param>
void Options::processEvents(sf::Event t_event)
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
/// Updates the Button objects.
/// </summary>
/// <param name="t_mousePos">The mouse's position on the screen.</param>
void Options::update(sf::Vector2i t_mousePos)
{
	m_backButton->update(t_mousePos);
}

/// <summary>
/// Draws all what's happening on the options screen.
/// </summary>
/// <param name="t_window">The screen to draw to.</param>
void Options::render(sf::RenderWindow& t_window)
{
	m_backButton->render(t_window);
	t_window.setView(t_window.getDefaultView());
}
