#include "Enemy.h"

Enemy::Enemy(Player& tPlayer) : player(tPlayer)
{
	texture.loadFromFile("texture.png");
	rectSprite = {300,200,100,100};
	sprite.setTexture(texture);
	sprite.setOrigin(50,50);
	sprite.setPosition(1000, -100);
}

void Enemy::update()
{
	collisionConsequence();
	animation();
	sprite.move(vecEnemyVelocity);
}

void Enemy::animation()
{
	if (enemyClock.getElapsedTime().asMilliseconds() > 400)
	{
		if (rectSprite.left == 0)
			rectSprite.left += 300;
		else
			rectSprite.left -= 100;
		enemyClock.restart();
	}
	sprite.setTextureRect(rectSprite);
}

void Enemy::followPlayer()
{
	if (player.sprite.getPosition().x > sprite.getPosition().x)
		vecEnemyVelocity.x = enemyVelocity;
	else
		vecEnemyVelocity.x = -enemyVelocity;

	if (player.sprite.getPosition().y > sprite.getPosition().y)
		vecEnemyVelocity.y = enemyVelocity;
	else
		vecEnemyVelocity.y = -enemyVelocity;
}

void Enemy::collision()
{
	if (player.sprite.getPosition().x + 100 > sprite.getPosition().x && player.sprite.getPosition().x - 30 < sprite.getPosition().x &&
		player.sprite.getPosition().y + 100 > sprite.getPosition().y && player.sprite.getPosition().y - 30 < sprite.getPosition().y)
	{
		isColision = true;
	}
	else
	{
		isColision = false;
	}
}

void Enemy::collisionConsequence()
{
	collision();
	if (isColision)
	{
		if (!isHiding || !wasCaptured)
		{
			collisionClock.restart();
		}

		if (player.isSuperState)
		{
			isHiding = true;
		}
		else
		{
			wasCaptured = true;
		}
	}

	if (isHiding)
	{

		vecEnemyVelocity.x = 18;
		vecEnemyVelocity.y = 0;
		if (collisionClock.getElapsedTime().asSeconds() > 3)
		{
			sprite.setPosition(1300, sprite.getPosition().y);
			isHiding = false;
		}
	}
	else if (wasCaptured)
	{
		vecEnemyVelocity.x = 0;
		vecEnemyVelocity.y = -7;
		player.playerVelocity = 0.5;
		if (collisionClock.getElapsedTime().asSeconds() > 4)
		{
			sprite.setPosition(sprite.getPosition().x, -200);
			wasCaptured = false;
			player.playerVelocity = 7;
		}
	}
	else
	followPlayer();
} 