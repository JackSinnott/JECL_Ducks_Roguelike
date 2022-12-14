#pragma once
#include "Globals.h"
#include <unordered_map>
#include "TextureManager.h"

#include "CombatSystem.h"
#include "Grid.h"

class Enemy
{
public:
	Enemy(EnemyType t_type, float t_posX, float t_posY);

	void update();
	void move();
	void CalculateDamageToPlayer(int t_playerAC);
	void render(sf::RenderWindow& t_window);
	int GetArmourClass();
	int getRoom() { return room; }

	sf::Vector2i getEnemyPositionInGrid() { return sf::Vector2i(row, col); }
private:

	int m_armourClass = 2;
	int health = 20;
	int xp = 10;

	int GetDamage();

	const EnemyType m_type;
	sf::Sprite m_enemy;
	std::shared_ptr<sf::Texture> m_enemyTexture;
	static std::unordered_map<EnemyType, sf::IntRect> m_rects;

	int row;
	int col;

	int room;

	//Grid* m_grid = nullptr;
};
