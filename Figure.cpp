#include "Figure.h"

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
}

void Figure::makeActive()
{
	sprite.setColor(sf::Color(Dark, Dark, Dark));
}


bool Figure::isNeighbour(int x, int y, int n_X, int n_Y)
{
	if (((x - n_X == 1 || x - n_X == -1) && (y - n_Y == 1 || y - n_Y == -1 || y - n_Y == 0)) || (x - n_X == 0 && (y - n_Y == 1 || y - n_Y == -1)))
	{
		return true;
	}
	return false;
}

int Figure::getPositionX() 
{
	return sprite.getPosition().x;
}

int Figure::getPositionY()
{
	return sprite.getPosition().y;
}