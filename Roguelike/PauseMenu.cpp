#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	sf::Vector2f buttonSize = sf::Vector2f(500, 100);
	m_backButton = new Button(sf::Vector2f((G_VIEW_WIDTH - buttonSize.x) / 2, G_VIEW_HEIGTH - (buttonSize.y * 3)),
		buttonSize, "BACK TO GAME", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);

	sf::Vector2f menuButtonSize = sf::Vector2f(500, 100);
	m_menuBackButton = new Button(sf::Vector2f((G_VIEW_WIDTH - menuButtonSize.x) / 2, G_VIEW_HEIGTH - (menuButtonSize.y * 1.5)),
		menuButtonSize, "BACK TO MAIN MENU", sf::Color::Yellow, sf::Color::Red, sf::Color::Green);

	m_gameOverText.setFont(g_font);
	m_gameOverText.setString("GAME PAUSED");
	m_gameOverText.setCharacterSize(150);
	m_gameOverText.setFillColor(sf::Color::White);
	m_gameOverText.setPosition(G_VIEW_WIDTH / 2, G_VIEW_HEIGTH / 3);
	m_gameOverText.setOrigin(m_gameOverText.getLocalBounds().width / 2.0f, m_gameOverText.getLocalBounds().height / 2.0f);
}

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

void PauseMenu::update(sf::Vector2i t_mousePos)
{
	m_menuBackButton->update(t_mousePos);
	m_backButton->update(t_mousePos);
}

void PauseMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_gameOverText);

	m_menuBackButton->render(t_window);
	m_backButton->render(t_window);
	t_window.setView(t_window.getDefaultView());
}
