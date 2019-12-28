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
		(*p_field)[(mousePos.x / 100) - 1][(mousePos.y / 75) - 1].makeFieldInactive(); 
		(*p_field)[(mousePos.x / 100) - 1][(mousePos.y / 75)].makeFieldInactive();
		(*p_field)[(mousePos.x / 100) - 1][(mousePos.y / 75) + 1].makeFieldInactive();
		(*p_field)[(mousePos.x / 100)][(mousePos.y / 75) - 1].makeFieldInactive();
		(*p_field)[(mousePos.x / 100)][(mousePos.y / 75) + 1].makeFieldInactive();
		(*p_field)[(mousePos.x / 100) + 1][(mousePos.y / 75) - 1].makeFieldInactive();
		(*p_field)[(mousePos.x / 100) + 1][(mousePos.y / 75)].makeFieldInactive();
		(*p_field)[(mousePos.x / 100) + 1][(mousePos.y / 75) + 1].makeFieldInactive();
		makeInactive();
	}
	else
	{
		(*p_field)[(mousePos.x / 100) - 1][(mousePos.y / 75) - 1].makeFieldActive();
		(*p_field)[(mousePos.x / 100) - 1][(mousePos.y / 75)].makeFieldActive();
		(*p_field)[(mousePos.x / 100) - 1][(mousePos.y / 75) + 1].makeFieldActive();
		(*p_field)[(mousePos.x / 100)][(mousePos.y / 75) - 1].makeFieldActive();
		(*p_field)[(mousePos.x / 100)][(mousePos.y / 75) + 1].makeFieldActive();
		(*p_field)[(mousePos.x / 100) + 1][(mousePos.y / 75) - 1].makeFieldActive();
		(*p_field)[(mousePos.x / 100) + 1][(mousePos.y / 75)].makeFieldActive();
		(*p_field)[(mousePos.x / 100) + 1][(mousePos.y / 75) + 1].makeFieldActive();
		makeActive();
	}
}

void meleeGroundMech::move(Field(*p_field)[8][8], sf::Vector2i mousePos)
{
	if ((*p_field)[(mousePos.x / 100)][(mousePos.y / 75)].possibleMove)
	{
		sprite.setPosition(((mousePos.x / 100)*100), ((mousePos.y / 75))*75);
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


