#include "Player.h"

Player::Player(Settings& set, Burger& tBurger) : playerSet(set), burger(tBurger)
{
	setTexture();
	sprite.setPosition(playerSet.width() / 2, playerSet.height() / 2);
	sprite.setOrigin(size / 2, size / 2);
}

void Player::setTexture()
{
	texture.loadFromFile("texture.png");
	rectSprite = { 0, 0, 100, 99 };
	sprite.setTexture(texture);
}

void Player::update()
{
	keyboardControl();
	wallLogic();
	eating();
	superState();
	animation();
	sprite.setTextureRect(rectSprite);
}

void Player::keyboardControl()
{
	sprite.move(vecPlayerVelocity);
	if (playerSet.isPressedLeft())
	{
		vecPlayerVelocity.x = -playerVelocity;
	}
	else if (playerSet.isPressedRight())
	{
		vecPlayerVelocity.x = playerVelocity;
	}
	else { vecPlayerVelocity.x = 0; }

	if (playerSet.isPressedUp())
	{
		vecPlayerVelocity.y = -playerVelocity;
	}
	else if (playerSet.isPressedDown())
	{
		vecPlayerVelocity.y = playerVelocity;
	}
	else { vecPlayerVelocity.y = 0; }
}

void Player::wallLogic()
{
	if (sprite.getPosition().x > playerSet.width())
	{
		sprite.setPosition({ sprite.getPosition().x - playerSet.width(), sprite.getPosition().y });
	}

	if (sprite.getPosition().x < 0)
	{
		sprite.setPosition({ sprite.getPosition().x + playerSet.width(), sprite.getPosition().y });
	}

	if (sprite.getPosition().y < 0)
	{
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y + playerSet.height() });
	}

	if (sprite.getPosition().y > playerSet.height())
	{
		sprite.setPosition({ sprite.getPosition().x, sprite.getPosition().y - playerSet.height() });
	}
}

void Player::animation()
{
	if (playerSet.isPressedUp() || playerSet.isPressedDown() ||
		playerSet.isPressedRight() || playerSet.isPressedLeft())
	{
		if (playerClock.getElapsedTime().asMilliseconds() > 200)
		{
			if (rectSprite.left == 200 || rectSprite.left == 100)
				rectSprite.left = 0;
			else
				rectSprite.left += 200;
			playerClock.restart();
		}
	}
	else
		rectSprite.left = 100;
}

void Player::eating()
{
	if (sprite.getPosition().x + 100 > burger.sprite.getPosition().x && sprite.getPosition().x - 40 < burger.sprite.getPosition().x &&
		sprite.getPosition().y + 100 > burger.sprite.getPosition().y && sprite.getPosition().y - 40 < burger.sprite.getPosition().y &&
		burger.isVisible)
	{
		burger.isVisible = false;
		isSuperState = true;
	}
}

void Player::superState()
{
	if (superStateClock.getElapsedTime().asSeconds() < 4 && isSuperState)
	{
		rectSprite.top = 100;
		playerVelocity = 14;
	}
	else
	{
		rectSprite.top = 0;
		isSuperState = false;
		playerVelocity = 7;
		superStateClock.restart();
	}
}