#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Settings.h"

class Enemy
{
public:
	Enemy(Player& tPlayer);
	~Enemy() = default;
	sf::Sprite sprite;
	void update();
	void collision();
	void collisionConsequence();
	
private:
	sf::Texture texture;
	sf::IntRect rectSprite;
	sf::Clock enemyClock;
	sf::Clock collisionClock;
	float enemyVelocity = 2;
	sf::Vector2f vecEnemyVelocity{ 0,0 };
	Player& player;
	bool isColision = false;
	bool isHiding = false;
	bool wasCaptured = false;
	void animation();
	void followPlayer();
};