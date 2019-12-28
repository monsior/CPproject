#include "Field.h"

Field::Field()
{
	texture.loadFromFile("field.png");
	sprite.setPosition(0, 0);
	sprite.setTexture(texture);
	possibleMove = false;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}

void Field::setPosition(float t_X, float t_Y)
{
	sprite.setPosition(t_X, t_Y);
}

void Field::makeFieldActive()
{
	possibleMove = true;
	sprite.setColor(sf::Color::Blue);
}

void Field::makeFieldInactive()
{
	possibleMove = false;
	sprite.setColor(sf::Color::White);
}

sf::Vector2f Field::getPosition()
{
	return sprite.getPosition();
}
