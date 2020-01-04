#pragma once
#include "Figure.h"
#include "enemyGround.h"

extern bool playerTurn;

class meleeGroundMech : public Figure
{
public:
	meleeGroundMech();
	~meleeGroundMech() = default;
	void move(Field(*p_field)[8][8], sf::Vector2i pixelPos, enemyGround(*p_enemy)[3]);
	void attack(enemyGround(*p_enemy)[3]);
	void selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos);
};

