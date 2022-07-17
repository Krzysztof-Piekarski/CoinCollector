#include "Burger.h"

Burger::Burger(Settings& tSet) : set(tSet)
{
	setTexture();
	setLocation();
	sprite.setOrigin(50,50);
}

void Burger::setTexture()
{
	texture.loadFromFile("texture.png");
	sprite.setTexture(texture);
	sprite.setTextureRect({ 300,100,100,100 });
}

void Burger::update()
{
	if (isVisible)
	{
		sprite.setTextureRect({ 300,0,100,100 });
	}
	else
	{
		sprite.setTextureRect({ 300,100,100,100 });
	}

	if (!isVisible)
	{
		if (burgerClock.getElapsedTime().asSeconds() > 5)
		{
			setLocation();
			isVisible = true;
			burgerClock.restart();
		}
	}
	else
	{
		if (burgerClock.getElapsedTime().asSeconds() > 2)
		{
			isVisible = false;
			burgerClock.restart();
		}
	}
}

void Burger::setLocation()
{
	int w(set.width()), h(set.height());
	sprite.setPosition(rand() % (w-100) + 50, rand() % (h-100) + 50);
}