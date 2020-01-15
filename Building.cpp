#include "Building.h"
#include <iostream>

Building::Building(float x, float y)
{
	sprite.setPosition(x, y);
	texture.loadFromFile("Building.png");
	sprite.setTexture(texture);
	destroyed = false;
}

void Building::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}

int Building::getPositionX()
{
	return int(sprite.getPosition().x);
}

int Building::getPositionY()
{
	return int(sprite.getPosition().y);
}

void Building::setPosition(float x, float y)
{
	sprite.setPosition(100 * x, 75 * y);
}

void Building::operator --()
{
	sprite.setColor(sf::Color::Black);
	destroyed = true;
	std::cout << "You've lost";
	playerMeleeTurn = false;
	playerRangedTurn = false;
}

bool Building::getDestroyed()
{
	return destroyed;
}