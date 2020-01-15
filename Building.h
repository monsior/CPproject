#pragma once
#include <SFML/Graphics.hpp>

extern bool playerMeleeTurn;
extern bool playerRangedTurn;

class Building : public sf::Drawable
{
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	bool destroyed;
public:
	Building(float x = 0, float y = 0);
	int getPositionX();
	int getPositionY();
	void setPosition(float x, float y);
	void operator --();
	bool getDestroyed();

};

