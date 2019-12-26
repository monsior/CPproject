#include "meleeGroundMech.h"
#include <iostream>

meleeGroundMech::meleeGroundMech()
{
	texture.loadFromFile("mech.png");
	sprite.setTexture(texture);
}

void meleeGroundMech::move(sf::Vector2i pixelPos)
{
	// move left
	if (pixelPos.x < sprite.getPosition().x && pixelPos.x > sprite.getPosition().x - 100)
	{
		setPosition(sprite.getPosition().x - 100, sprite.getPosition().y);
		makeInactive();
	}
	// move right
	else if (pixelPos.x > sprite.getPosition().x + 100 && pixelPos.x < sprite.getPosition().x + 200)
	{
		setPosition(sprite.getPosition().x + 100, sprite.getPosition().y);
		makeInactive();
	}
	// move up
	if (pixelPos.y < sprite.getPosition().y && pixelPos.y > sprite.getPosition().y-75)
	{
		setPosition(sprite.getPosition().x, sprite.getPosition().y - 75);
		makeInactive();
	}

	// move down
	else if (pixelPos.y > sprite.getPosition().y + 75 && pixelPos.y < sprite.getPosition().y + 150)
	{
		setPosition(sprite.getPosition().x, sprite.getPosition().y + 75);
		makeInactive();
	}
}

//void meleeGroundMech::moveDown()
//{
//	setPosition(sprite.getPosition().x, sprite.getPosition().y - 75);
//}
//
//void meleeGroundMech::moveRight()
//{
//	setPosition(sprite.getPosition().x + 100, sprite.getPosition().y);
//}
//
//void meleeGroundMech::moveLeft()
//{
//	setPosition(sprite.getPosition().x-100, sprite.getPosition().y);
//}