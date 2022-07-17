#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Text
{
public:
	Text(Settings& tSet);
	~Text() = default;
	void update();
	void displayTime();
	sf::Text text;
	sf::Clock textClock;
	std::string string;

private:
	Settings& textSet;
	sf::Font font;
};
