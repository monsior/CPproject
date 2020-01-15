#include "meleeGroundMech.h"

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

void meleeGroundMech::move(Field(*p_field)[8][8], sf::Vector2i mousePos, enemyGround(*p_enemy)[3])
{
	if (active)
	{
		if ((*p_field)[(mousePos.x / 100)][(mousePos.y / 75)].possibleMove)
		{
			sprite.setPosition(float((mousePos.x / 100) * 100), float((mousePos.y / 75) * 75));
			attack(p_enemy);

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					((*p_field)[(i)][j]).makeFieldInactive();
				}
			}
			makeInactive();
			playerMeleeTurn = false;
		}
	}
}

void meleeGroundMech::attack(enemyGround(*p_enemy)[3])
{
	for (int i = 0; i < 3; i++)
	{
	//	if ((*p_enemy)[i].getPositionX() == sprite.getPosition().x && (*p_enemy)[i].getPositionY() == sprite.getPosition().y)
		//	--(*p_enemy)[i];
		//if ((*p_enemy)[i].getPositionX() >= sprite.getPosition().x - 100 && (*p_enemy)[i].getPositionX() <= sprite.getPosition().x + 100 && (*p_enemy)[i].getPositionY() >= sprite.getPosition().y - 75 && (*p_enemy)[i].getPositionY() <= sprite.getPosition().y + 75)
		if ((*p_enemy)[i].getPositionX() == sprite.getPosition().x && (*p_enemy)[i].getPositionY() == sprite.getPosition().y)
				--(*p_enemy)[i];
	}
}

