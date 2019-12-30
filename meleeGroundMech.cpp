#include "meleeGroundMech.h"
#include <iostream>

meleeGroundMech::meleeGroundMech()
{
	texture.loadFromFile("mech.png");
	sprite.setTexture(texture);
}

void meleeGroundMech::selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos)
{
	if (active)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{

				if (isNeighbour(1, j, mousePos.x / 100, mousePos.y / 75))
				{
					(*p_field)[1][j].makeFieldInactive();
				}
			}
		}
		makeInactive();
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
			
				if (isNeighbour(i, j, mousePos.x / 100, mousePos.y / 75))
				{
					(*p_field)[i][j].makeFieldActive();
				}
			}
		}

		makeActive();
	}
}

void meleeGroundMech::move(Field(*p_field)[8][8], sf::Vector2i mousePos)
{
	if ((*p_field)[(mousePos.x / 100)][(mousePos.y / 75)].possibleMove)
	{



		sprite.setPosition(((mousePos.x / 100) * 100), ((mousePos.y / 75)) * 75);
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				((*p_field)[(i)][j]).makeFieldInactive();
			}
		}
		makeInactive();
	}
	
}


