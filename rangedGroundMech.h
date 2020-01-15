#pragma once
#include "Figure.h"
#include "enemyGround.h"

extern bool playerRangedTurn;

class rangedGroundMech : public Figure
{
	bool isInSameLine(int x, int y, int n_X, int n_Y);
public:
	rangedGroundMech();
	~rangedGroundMech() = default;
	void move(Field(*p_field)[8][8], sf::Vector2i pixelPos);
	void selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos, enemyGround(*p_enemy)[3]);
	void attack(enemyGround(*p_enemy)[3], sf::Vector2i pixelPos);
};