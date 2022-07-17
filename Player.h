#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Burger.h"

class Player
{
public:
	sf::Sprite sprite;
	Player(Settings& set, Burger& tBurger);
	~Player() = default;
	void update();
	bool isSuperState = false;
	float playerVelocity = 7;
	sf::Vector2f vecPlayerVelocity{ playerVelocity,playerVelocity };
	
private:
	sf::Texture texture;
	sf::IntRect rectSprite;
	sf::Clock playerClock, superStateClock;
	Settings& playerSet;
	Burger& burger;
	void setTexture();
	void animation();
	void keyboardControl();
	void wallLogic();
	void superState();
	void eating();
	float size = 50;
};
