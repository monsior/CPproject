#pragma once
#include "Figure.h"
#include "Building.h"

extern bool playerTurn;

class enemyGround : public Figure
{
public:
	enemyGround();
	void move(Building(*p_building)[2]);
};

