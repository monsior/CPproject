#include "Building.h"

Building::Building(int x, int y)
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
	return sprite.getPosition().x;
}

int Building::getPositionY()
{
	return sprite.getPosition().y;
}

void Building::setPosition(int x, int y)
{
	sprite.setPosition(100 * x, 75 * y);
}

void Building::operator --()
{
	sprite.setColor(sf::Color::Black);
	destroyed = true;
}

bool Building::getDestroyed()
{
	return destroyed;
}