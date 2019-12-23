#include "Field.h"
#include <iostream>


Field::Field() 
{
	texture.loadFromFile("field.png");
	sprite.setPosition(0, 0); 
	sprite.setTexture(texture);
}


void Field::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}

void Field::setPosition(float t_X, float t_Y)
{
	sprite.setPosition(t_X, t_Y);
}

sf::Vector2f Field::getPosition()
{
	return sprite.getPosition(); 
}

void Field::changeColor()
{
	texture.loadFromFile("fieldActive.png");
	sprite.setTexture(texture);
}


