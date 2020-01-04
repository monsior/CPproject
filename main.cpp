#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Figure.h"
#include "meleeGroundMech.h"
#include <iostream>
#include "enemyGround.h"
#include "Building.h"
#include "rangedGroundMech.h"

constexpr auto windowsHeight = 800.f;
constexpr auto windowsWidth = 600.f;
bool playerTurn = true;

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowsHeight, windowsWidth), "SFMLGame", sf::Style::Titlebar | sf::Style::Close);

	Field field[8][8];
	Field(*p_field)[8][8] = &field;
	field[0][3].makeWater();
	field[1][3].makeWater();
	field[2][3].makeWater();
	field[5][0].makeWater();
	field[5][1].makeWater();
	field[7][0].makeWater();
	field[7][1].makeWater();
	field[7][2].makeWater();

	Building building[3];
	Building(*p_building)[3] = &building;
	building[0].setPosition(0, 1);
	building[1].setPosition(6, 0);
	building[2].setPosition(1, 6);
	
	meleeGroundMech mech;
	rangedGroundMech ranged;
	enemyGround enemy[3];
	enemyGround(*p_enemy)[3] = &enemy;

	mech.setPosition(4, 2);
	ranged.setPosition(0, 7);
	enemy[0].setPosition(3, 1);
	enemy[1].setPosition(7, 4);
	enemy[2].setPosition(6, 7);


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			field[i][j].setPosition((windowsHeight / 8 * i), (windowsWidth / 8 * j));
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if (playerTurn)
				{
					if (mousePos.x > mech.getPositionX() && mousePos.x < mech.getPositionX() + 100 && mousePos.y > mech.getPositionY() && mousePos.y < mech.getPositionY() + 75)
					{
						mech.selectFigure(p_field, mousePos);
					}
					if (mousePos.x > ranged.getPositionX() && mousePos.x < ranged.getPositionX() + 100 && mousePos.y > ranged.getPositionY() && mousePos.y < ranged.getPositionY() + 75)
					{
						ranged.selectFigure(p_field, mousePos, p_enemy);
					}
						mech.move(p_field, mousePos, p_enemy);
						ranged.move(p_field, mousePos);
						ranged.attack(p_enemy, mousePos);
						//playerTurn = false;

				}
				break;
			}
			if (!playerTurn)
			{
				//enemy[0].move(p_building);
				//enemy[1].move(p_building);
				//enemy[2].move(p_building);
				playerTurn = true;
			}
		}

		window.clear();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				window.draw(field[i][j]);
			}
		}

		window.draw(mech);
		window.draw(ranged);
		window.draw(enemy[0]);
		window.draw(enemy[1]);
		window.draw(enemy[2]);
		window.draw(building[0]);
		window.draw(building[1]);
		window.draw(building[2]);
		window.display();
	}

	return 0;
}