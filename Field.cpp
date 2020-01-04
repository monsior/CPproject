#include "Field.h"
#include <iostream>

Field::Field()
{
	sprite.setPosition(0, 0);
	texture.loadFromFile("field.png");
	sprite.setTexture(texture);
	possibleMove = false;
	fieldType = "ground";
	inRange = false;
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

void Field::makeFieldInRange()
{
	//possibleMove = true;
	sprite.setColor(sf::Color::Red);
	inRange = true;
}

sf::Vector2f Field::getPosition()
{
	return sprite.getPosition();
}

void Field::makeWater() 
{ 
	texture.loadFromFile("water.png");
	sprite.setTexture(texture);
	fieldType = "water";
}

std::string Field::getType()
{
	return fieldType;
}

void Field::setType(std::string type)
{
	fieldType = type;
}
