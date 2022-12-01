#include "GameOver.h"

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

void GameOver::update(sf::Vector2i t_mousePos)
{
	m_backButton->update(t_mousePos);
}

void GameOver::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_loseText);
	m_backButton->render(t_window);
}
