#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Figure.h"
#include "meleeGroundMech.h"
#include <iostream>

constexpr auto windowsHeight = 800.f;
constexpr auto windowsWidth = 600.f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowsHeight, windowsWidth), "SFMLGame");

	Field field[8][8];
	Field(*p_field)[8][8] = &field;

	meleeGroundMech mech[3];

	mech[0].setPosition(300, 150);


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

					if (mousePos.x > mech[0].sprite.getPosition().x && mousePos.x < mech[0].sprite.getPosition().x + 100 && mousePos.y > mech[0].sprite.getPosition().y&& mousePos.y < mech[0].sprite.getPosition().y + 75)
					{
						//mech[i].makeActive();
						mech[0].selectFigure(p_field, mousePos);

					}
					mech[0].move(p_field, mousePos);
					//mech[0].makeInactive();


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

		window.draw(mech[0]);
		window.display();
	}

	return 0;
}