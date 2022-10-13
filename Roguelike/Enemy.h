#pragma once
#include "Globals.h"

class Enemy
{
public:
	Enemy(EnemyType t_type, float t_posX, float t_posY);

	void update();
	void render(sf::RenderWindow& t_window);
private:
	const EnemyType m_type;
	sf::RectangleShape m_enemy;
};
