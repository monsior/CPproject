#include "rangedGroundMech.h"

rangedGroundMech::rangedGroundMech()
{
	texture.loadFromFile("ranged.png");
	sprite.setTexture(texture);
}

void rangedGroundMech::selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos)
{
		if (active)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (isNeighbour(i, j, mousePos.x / 100, mousePos.y / 75))
					{
						if ((*p_field)[i][j].getType() == "ground")
						{
							(*p_field)[i][j].makeFieldInactive();
						}
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
						if ((*p_field)[i][j].getType() == "ground")
						{
							(*p_field)[i][j].makeFieldActive();
						}
					}
				}
			}
			makeActive();
		}
}

void rangedGroundMech::move(Field(*p_field)[8][8], sf::Vector2i mousePos)
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
		//playerTurn = false;
	}
}


