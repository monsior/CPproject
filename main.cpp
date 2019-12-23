#include <SFML/Graphics.hpp>
#include "Field.h"
constexpr auto windowsHeight = 800.f;
constexpr auto windowsWidth = 600.f;

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
			if (event.type == sf::Event::Closed)
				window.close();
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