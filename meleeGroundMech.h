#pragma once
#include "Figure.h"

extern bool playerTurn;

class meleeGroundMech : public Figure
{
public:
	meleeGroundMech();
	~meleeGroundMech() = default;
	void move(Field(*p_field)[8][8], sf::Vector2i pixelPos);
	virtual void selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos) override;
};