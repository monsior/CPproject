#include "enemyGround.h"
#include <iostream>

enemyGround::enemyGround()
{
	texture.loadFromFile("enemyGround.png");
	sprite.setTexture(texture);
}

void enemyGround::move(Building building) 
{
	std::cout << playerTurn;
	if (!playerTurn)
	{
		// move left
		if (sprite.getPosition().x > building.getPositionX())
		{
			sprite.setPosition(sprite.getPosition().x - 100, sprite.getPosition().y);
		}
		// move right
		else if (sprite.getPosition().x < building.getPositionX())
		{
			sprite.setPosition(sprite.getPosition().x + 100, sprite.getPosition().y);
		}
		// move down
		if (sprite.getPosition().y > building.getPositionY())
		{
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 75);
		}
		// move up
		else if (sprite.getPosition().y < building.getPositionY())
		{
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 75);
		}
		
	}
	playerTurn = true;
}
