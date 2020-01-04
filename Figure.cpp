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

void Figure::setPosition(float t_X, float t_Y)
{
	sprite.setPosition(100 * t_X, 75 * t_Y);
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

void Figure::changeFieldType(Field(*p_field)[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//if ((*p_field)[i][j].getPosition().x == sprite.getPosition().x && (*p_field)[i][j].getPosition().y == sprite.getPosition().y)
			//{
				(*p_field)[getPositionX() / 100][(getPositionY() / 75)].setType("figure");
				(*p_field)[1][1].makeWater();
			//}
		}
	}

	
}