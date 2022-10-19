#include "Enemy.h"

Enemy::Enemy(EnemyType t_type, float t_posX, float t_posY) : m_type(t_type)
{
	m_enemy.setPosition(sf::Vector2f(t_posX, t_posY));
	m_enemy.setSize(sf::Vector2f(100, 100));
	m_enemy.setFillColor(sf::Color::Red);
}

void Enemy::update()
{

}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemy);
}
