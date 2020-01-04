#pragma once
#include "Figure.h"

//extern bool playerTurn;

class rangedGroundMech : public Figure
{
public:
	rangedGroundMech();
	~rangedGroundMech() = default;
	void move(Field(*p_field)[8][8], sf::Vector2i pixelPos);
	void selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos);
};