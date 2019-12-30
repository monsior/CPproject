#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Figure.h"
#include "meleeGroundMech.h"
#include <iostream>

constexpr auto windowsHeight = 800.f;
constexpr auto windowsWidth = 600.f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowsHeight, windowsWidth), "SFMLGame", sf::Style::Titlebar | sf::Style::Close);

	Field field[8][8];
	Field(*p_field)[8][8] = &field;
	
	meleeGroundMech mech;

	mech.setPosition(300,150);


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

					if (mousePos.x > mech.sprite.getPosition().x && mousePos.x < mech.sprite.getPosition().x + 100 && mousePos.y > mech.sprite.getPosition().y&& mousePos.y < mech.sprite.getPosition().y + 75)
					{
						mech.selectFigure(p_field, mousePos);
					}
					mech.move(p_field, mousePos);


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
		window.display();
	}

	return 0;
}