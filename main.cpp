#include <SFML/Graphics.hpp>
#include "Field.h"
#include <iostream>
constexpr auto windowsHeight = 800.f;
constexpr auto windowsWidth = 600.f;

int whichFieldX(int x);
int whichFieldY(int y);

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowsHeight, windowsWidth), "SFMLGame"); 

	Field field[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			field[i][j].setPosition(80 * i, 60 * j);
		}
	}



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				
				
				field[whichFieldX(pixelPos.x)][whichFieldY(pixelPos.y)].changeColor();
				break;
			}
		}

		window.clear();
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				window.draw(field[i][j]);
			}
		}
		
		window.display();
	}

	return 0;
}

int whichFieldX(int x)
{
	return x / 80;
}

int whichFieldY(int y)
{
	return y / 60;
}