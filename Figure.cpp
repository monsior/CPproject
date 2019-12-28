#include "Figure.h"
#include <iostream>



Figure::Figure()
{
	sprite.setPosition(0, 0);
	active = false;
}

void Figure::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}

void Figure::selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos)
{
	if (active)
	{
		(*p_field)[(mousePos.x / 100)][(mousePos.y / 75)].makeFieldInactive();
		makeActive();
	}
	else
	{
		(*p_field)[mousePos.x / 100][mousePos.y / 75].makeFieldActive();
		makeInactive();
	}
}

void Figure::setPosition(float t_X, float t_Y)
{
	sprite.setPosition(t_X, t_Y);
}

bool Figure::isActive()
{
	return active;
}

void Figure::makeInactive()
{
	sprite.setColor(sf::Color::White);
	//active = true; 
}

void Figure::makeActive()
{
	sprite.setColor(sf::Color(Dark, Dark, Dark));
	//active = false;
}