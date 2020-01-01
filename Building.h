#pragma once
#include <SFML/Graphics.hpp>

class Building : public sf::Drawable
{
public:
	Building(int x = 0, int y = 0);
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

