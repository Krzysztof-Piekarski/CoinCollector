#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Player.h"

class Coin
{
public:
	Coin(Settings& tSet, Player& tPlayer);
	sf::Sprite sprite;
	sf::IntRect rectSprite;
	void setNewPosition();
	void collect();
	void update();

private:
	sf::Texture texture;
	sf::Clock coinClock;
	sf::Vector2f coinPosition;
	void animation();
	void attractionRange();
	void attraction();
	bool isAttracted = false;
	float attractionVelocity = 1;
	sf::Vector2f coinVelocity{ 0,0 };
	bool reverseAnimation = false;
	Settings& coinSet;
	Player& player;
};
