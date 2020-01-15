#include "rangedGroundMech.h"
#include <iostream>

rangedGroundMech::rangedGroundMech()
{
	texture.loadFromFile("ranged.png");
	sprite.setTexture(texture);
}

void rangedGroundMech::selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos, enemyGround(*p_enemy)[3])
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
					if (isInSameLine(i, j, mousePos.x / 100, mousePos.y / 75) && !isNeighbour(i, j, mousePos.x / 100, mousePos.y / 75))
					{
						(*p_field)[i][j].makeFieldInRange();
						//attack(p_enemy);
					}
				}
			}
			makeActive();
		}
}

void rangedGroundMech::move(Field(*p_field)[8][8], sf::Vector2i mousePos)
{
	if (active)
	{
		if ((*p_field)[(mousePos.x / 100)][(mousePos.y / 75)].possibleMove)
		{
			sprite.setPosition(float((mousePos.x / 100) * 100), float((mousePos.y / 75) * 75));

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					((*p_field)[(i)][j]).makeFieldInactive();
				}
			}
			makeInactive();
			playerRangedTurn = false;
		}
	}
}

bool rangedGroundMech::isInSameLine(int x, int y, int n_X, int n_Y)
{
	if (x == n_X || y == n_Y) 
	{
		return true;
	}
	return false;
}


void rangedGroundMech::attack(enemyGround(*p_enemy)[3], sf::Vector2i pixelPos)
{
	for (int i = 0; i < 3; i++)
	{
		if (pixelPos.x > (*p_enemy)[i].getPositionX() && pixelPos.x < (*p_enemy)[i].getPositionX() + 100 && pixelPos.y >(*p_enemy)[i].getPositionY() && pixelPos.y < (*p_enemy)[i].getPositionY() + 75 && (sprite.getPosition().x == (*p_enemy)[i].getPositionX() || sprite.getPosition().y == (*p_enemy)[i].getPositionY()))
		{
			--(*p_enemy)[i];
			playerRangedTurn = false;
		}
	}
}