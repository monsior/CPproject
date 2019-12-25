#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Figure.h"
#include "meleeGroundMech.h"
#include <iostream>

constexpr auto windowsHeight = 800.f;
constexpr auto windowsWidth = 600.f;

int whichFieldX(int x);
int whichFieldY(int y);

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowsHeight, windowsWidth), "SFMLGame"); 

	Field field[8][8];

	meleeGroundMech mech[3];
	
	mech[0].setPosition(0, 0);
	mech[1].setPosition(100, 75);
	mech[2].setPosition(200, 150);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			field[i][j].setPosition((windowsHeight/8 * i), (windowsWidth/8 * j));
		}
	}



	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				for (int i = 0; i < 3; i++)
				{
					if (pixelPos.x > mech[i].sprite.getPosition().x && pixelPos.x < mech[i].sprite.getPosition().x + 100 && pixelPos.y > mech[i].sprite.getPosition().y && pixelPos.y < mech[i].sprite.getPosition().y + 75)
					{
						mech[i].selectFigure();
						for (int j = 0; j < 3; j++)
						{
							if (j != i)
							{
								mech[j].makeInactive();
							}
						}
	/*					pixelPos = sf::Mouse::getPosition(window);
						if ((pixelPos.x < mech[i].sprite.getPosition().x - 100))
							mech[i].sprite.setPosition(mech[i].sprite.getPosition().x - 100, mech[i].sprite.getPosition().y);*/
							
					}
							
				}

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
		window.draw(mech[1]);
		window.draw(mech[2]);
		window.display();
	}

	return 0;
}

int whichFieldX(int x)
{
	return x / 100;
}

int whichFieldY(int y)
{
	return y / 75;
}