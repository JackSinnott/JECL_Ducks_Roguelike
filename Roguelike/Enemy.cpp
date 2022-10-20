#include "Enemy.h"

Enemy::Enemy(EnemyType t_type, float t_posX, float t_posY) : m_type(t_type)
{
	int xCoord = (int)t_posX - (int)t_posX % G_CELL_SIZE + G_CELL_SIZE / 2;
	int yCoord = (int)t_posY - (int)t_posY % G_CELL_SIZE + G_CELL_SIZE / 2;
	m_enemy.setOrigin(G_CELL_SIZE / 2, G_CELL_SIZE / 2);
	m_enemy.setPosition(sf::Vector2f(xCoord, yCoord));
	m_enemy.setSize(sf::Vector2f(G_CELL_SIZE, G_CELL_SIZE));
	m_enemy.setFillColor(sf::Color::Red);
}

void Enemy::update()
{

}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemy);
}
