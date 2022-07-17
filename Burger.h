#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Burger
{
public:
	Burger(Settings& set);
	~Burger() = default;
	sf::Sprite sprite;
	bool isVisible = false;
	void update();

private:
	sf::Texture texture;
	sf::Clock burgerClock;
	Settings& set;
	void setTexture();
	void setLocation();
};