#include "enemyGround.h"
#include <iostream>

enemyGround::enemyGround()
{
	texture.loadFromFile("enemyGround.png");
	sprite.setTexture(texture);
	dead = false;
}

void enemyGround::move(Building(*p_building)[3])
{
	int closestBuilding = 0;
	int distance = sqrt(((*p_building)[0].getPositionX() - sprite.getPosition().x) * ((*p_building)[0].getPositionX() - sprite.getPosition().x) + ((*p_building)[0].getPositionY() - sprite.getPosition().y) * ((*p_building)[0].getPositionY() - sprite.getPosition().y));
	for (int i = 0; i < 3; i++)
	{
		if (!(*p_building)[i].getDestroyed())
		{
			if (distance > sqrt(((*p_building)[i].getPositionX() - sprite.getPosition().x) * ((*p_building)[i].getPositionX() - sprite.getPosition().x) + ((*p_building)[i].getPositionY() - sprite.getPosition().y) * ((*p_building)[i].getPositionY() - sprite.getPosition().y)))
			{
				closestBuilding = i;
				distance = sqrt(((*p_building)[i].getPositionX() - sprite.getPosition().x) * ((*p_building)[i].getPositionX() - sprite.getPosition().x) + ((*p_building)[i].getPositionY() - sprite.getPosition().y) * ((*p_building)[i].getPositionY() - sprite.getPosition().y));
			}
		}
	}

	if (!dead)
	{
			// move left
			if (sprite.getPosition().x > (*p_building)[closestBuilding].getPositionX())
			{
				sprite.setPosition(sprite.getPosition().x - 100, sprite.getPosition().y);
			}
			// move right
			else if (sprite.getPosition().x < (*p_building)[closestBuilding].getPositionX())
			{
				sprite.setPosition(sprite.getPosition().x + 100, sprite.getPosition().y);
			}
			// move down
			if (sprite.getPosition().y > (*p_building)[closestBuilding].getPositionY())
			{
				sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 75);
			}
			// move up
			else if (sprite.getPosition().y < (*p_building)[closestBuilding].getPositionY())
			{
				sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 75);
			}
	}
	//playerTurn = true;
	for (int i = 0; i < 3; i++)
	{
		if (sprite.getPosition().x == (*p_building)[i].getPositionX() && sprite.getPosition().y == (*p_building)[i].getPositionY())
			--(*p_building)[i];
	}
}

void enemyGround::operator --()
{
	sprite.setColor(sf::Color::Red);
	dead = true;
}