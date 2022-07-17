#include "Settings.h"
#include <SFML/Graphics.hpp>

float Settings::width()
{
	return widthInPixels;
}

float Settings::height()
{
	return heightInPixels;
}

bool Settings::isPressedUp()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
}

bool Settings::isPressedDown()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

bool Settings::isPressedRight()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

bool Settings::isPressedLeft()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
}
