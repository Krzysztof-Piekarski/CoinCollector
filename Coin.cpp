#include "Coin.h"

Coin::Coin(Settings& tSet, Player& tPlayer) : coinSet(tSet), player(tPlayer)
{
	texture.loadFromFile("texture.png");
	rectSprite = { 0, 300, 100, 100 };
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSprite);
	sprite.setOrigin(30, 30);
	setNewPosition();
}

void Coin::update()
{
	attractionRange();
	attraction();
	collect();
	animation();
	sprite.move(coinVelocity);
}

void Coin::animation()
{
	if (coinClock.getElapsedTime().asMilliseconds() > 200)
	{
		if (rectSprite.left == 300)
			reverseAnimation = true;
		if (rectSprite.left == 0)
			reverseAnimation = false;
		
		if (!reverseAnimation)
			rectSprite.left += 100;
		else
			rectSprite.left -= 100;


		coinClock.restart();
		sprite.setTextureRect(rectSprite);
	}
}

void Coin::collect()
{
	if (player.sprite.getPosition().x + 100 > sprite.getPosition().x && player.sprite.getPosition().x - 30 < sprite.getPosition().x &&
		player.sprite.getPosition().y + 100 > sprite.getPosition().y && player.sprite.getPosition().y - 30 < sprite.getPosition().y)
	{
		coinSet.score += 1;
		setNewPosition();
		rectSprite.left = 0;
	}
}

void Coin::setNewPosition()
{
	int w(coinSet.width()), h(coinSet.height());
	sprite.setPosition(rand() % (w-100) +50, rand() % (h-100) + 50);
}

void Coin::attractionRange()
{
	if (player.sprite.getPosition().x + 200 > sprite.getPosition().x && player.sprite.getPosition().x - 200 < sprite.getPosition().x &&
		player.sprite.getPosition().y + 200 > sprite.getPosition().y && player.sprite.getPosition().y - 200 < sprite.getPosition().y)
		isAttracted = true;
	else
		isAttracted = false;
}

void Coin::attraction()
{
	if (isAttracted)
	{
		if (player.sprite.getPosition().x > sprite.getPosition().x)
			coinVelocity.x = attractionVelocity;
		else
			coinVelocity.x = -attractionVelocity;

		if (player.sprite.getPosition().y > sprite.getPosition().y)
			coinVelocity.y = attractionVelocity;
		else
			coinVelocity.y = -attractionVelocity;
	}
	else
	{
		coinVelocity.x = 0;
		coinVelocity.y = 0;
	}
}