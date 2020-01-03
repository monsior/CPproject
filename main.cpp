#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Figure.h"
#include "meleeGroundMech.h"
#include <iostream>
#include "enemyGround.h"
#include "Building.h"

constexpr auto windowsHeight = 800.f;
constexpr auto windowsWidth = 600.f;
bool playerTurn = true;
bool computerTurn = false;

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
	enemyGround enemy[3];

	//mech.setPosition(300, 150);
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

					if (mousePos.x > mech.getPositionX() && mousePos.x < mech.getPositionX() + 100 && mousePos.y > mech.getPositionY() && mousePos.y < mech.getPositionY() + 75)
					{
						mech.selectFigure(p_field, mousePos);
					}

					mech.move(p_field, mousePos);
					enemy[0].move(p_building);
					enemy[1].move(p_building);
					enemy[2].move(p_building);
					playerTurn = true;

				break;
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