#pragma once
#include "Globals.h"
#include <unordered_map>
#include "TextureManager.h"

class Enemy
{
public:
	Enemy(EnemyType t_type, float t_posX, float t_posY);

	void update();
	void render(sf::RenderWindow& t_window);
private:

	const EnemyType m_type;
	sf::Sprite m_enemy;
	std::shared_ptr<sf::Texture> m_enemyTexture;
	static std::unordered_map<EnemyType, sf::IntRect> m_rects;
};
