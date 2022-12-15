#include "PauseMenu.h"

/// <summary>
/// The default constructor.
/// </summary>
PauseMenu::PauseMenu()
{
	sf::Vector2f buttonSize = sf::Vector2f(500, 100);
	m_backButton = new Button(sf::Vector2f((G_VIEW_WIDTH - buttonSize.x) / 2, G_VIEW_HEIGTH - (buttonSize.y * 3)),
		buttonSize, "BACK TO GAME", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);

	sf::Vector2f menuButtonSize = sf::Vector2f(500, 100);
	m_menuBackButton = new Button(sf::Vector2f((G_VIEW_WIDTH - menuButtonSize.x) / 2, G_VIEW_HEIGTH - (menuButtonSize.y * 1.5)),
		menuButtonSize, "BACK TO MAIN MENU", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);

	m_gamePauseText.setFont(g_font);
	m_gamePauseText.setString("GAME PAUSED");
	m_gamePauseText.setCharacterSize(150);
	m_gamePauseText.setFillColor(sf::Color::White);
	m_gamePauseText.setPosition(G_VIEW_WIDTH / 2, G_VIEW_HEIGTH / 3);
	m_gamePauseText.setOrigin(m_gamePauseText.getLocalBounds().width / 2.0f, m_gamePauseText.getLocalBounds().height / 2.0f);
}

/// <summary>
/// Handles any events the player has triggered while on the Pause Screen.
/// </summary>
/// <param name="t_event">The SFML event.</param>
void PauseMenu::processEvents(sf::Event t_event)
{
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			m_backButton->onMouseDown();
			m_menuBackButton->onMouseDown();
		}
	}
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		if (t_event.key.code == sf::Mouse::Left)
		{
			if (m_backButton->onMouseUp())
			{
				g_gamestate = Gamestate::Gameplay;
			}
			if (m_menuBackButton->onMouseUp())
			{
				g_gamestate = Gamestate::MainMenu;
			}
		}
	}
}

/// <summary>
/// Updates the Button objects on the screen.
/// </summary>
/// <param name="t_mousePos">The mouse's position on the screen.</param>
void PauseMenu::update(sf::Vector2i t_mousePos)
{
	m_menuBackButton->update(t_mousePos);
	m_backButton->update(t_mousePos);
}

/// <summary>
/// Draws all what's happening on the pause screen.
/// </summary>
/// <param name="t_window">The screen to draw to.</param>
void PauseMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_gamePauseText);

	m_menuBackButton->render(t_window);
	m_backButton->render(t_window);
	t_window.setView(t_window.getDefaultView());
}
