#pragma once
#include "Globals.h"
#include <unordered_map>
#include "TextureManager.h"

#include "CombatSystem.h"

class Enemy
{
public:
	Enemy();

	void update(sf::Vector2i t_playerPos, int t_playerRoom, int t_enemyRoom);
	virtual void move(sf::Vector2i t_playerPos, int t_playerRoom, int t_enemyRoom) = 0;
	void CalculateDamageToPlayer(int t_playerAC);
	void render(sf::RenderWindow& t_window);
	int GetArmourClass();

	sf::Vector2i getEnemyPositionInGrid() { return sf::Vector2i(col, row); }

	inline void setMovementBoolUp(bool t_switch) { m_freeToMoveUp = t_switch; }
	inline bool canWeMoveUp() { return m_freeToMoveUp; }

	inline void setMovementBoolDown(bool t_switch) { m_freeToMoveDown = t_switch; }
	inline bool canWeMoveDown() { return m_freeToMoveDown; }

	inline void setMovementBoolLeft(bool t_switch) { m_freeToMoveLeft = t_switch; }
	inline bool canWeMoveLeft() { return m_freeToMoveLeft; }

	inline void setMovementBoolRight(bool t_switch) { m_freeToMoveRight = t_switch; }
	inline bool canWeMoveRight() { return m_freeToMoveRight; }

	inline void resetMovementBools(bool t_switch) {
		setMovementBoolUp(t_switch); setMovementBoolDown(t_switch);
		setMovementBoolLeft(t_switch); setMovementBoolRight(t_switch);
	}
protected:
	sf::IntRect spriteRec{ 0,160,16,16 };
	int m_armourClass = 2;
	int health = 20;
	int xp = 10;

	int GetDamage();

	EnemyType m_type = EnemyType::Bat;
	sf::Sprite m_enemy;
	std::shared_ptr<sf::Texture> m_enemyTexture;

	int row;
	int col;

	bool m_freeToMoveUp;
	bool m_freeToMoveDown;
	bool m_freeToMoveLeft;
	bool m_freeToMoveRight;

	void randomMovement();
	void moveTowardsPlayer(sf::Vector2i t_playerPos);
};
