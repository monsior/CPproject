#include "Figure.h"
#include <iostream>

sf::Uint8 Dark = 150;

Figure::Figure()
{
	sprite.setPosition(0, 0);
	active = false;
}

void Figure::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->sprite, state);
}

void Figure::selectFigure()
{
	if (active)
	{
		sprite.setColor(sf::Color::White);
		active = false;
	}
	else
	{
		sprite.setColor(sf::Color(Dark, Dark, Dark));
		active = true;
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
	active = true;
	selectFigure();
}