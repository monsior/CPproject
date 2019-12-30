#include "Field.h"
#include <iostream>

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
	//if (sprite.getPosition().x >= 0 && sprite.getPosition().x <= 800 && sprite.getPosition().y > 0 && sprite.getPosition().y <= 600)
	//{
	//std::cout << sprite.getPosition().y;
	
	possibleMove = true;
	sprite.setColor(sf::Color::Blue);
	//}
	//std::cout << sprite.getPosition().y << std::endl;
	
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
