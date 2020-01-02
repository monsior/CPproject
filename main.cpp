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
	field[2][2].makeWater();
	Building building(100, 75);
	
	meleeGroundMech mech;
	enemyGround enemy;

	mech.setPosition(300,150);
	enemy.setPosition(600, 150);


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
					enemy.move(building);

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
		window.draw(enemy);
		window.draw(building);
		window.display();
	}

	return 0;
}