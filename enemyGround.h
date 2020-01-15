#pragma once
#include "Figure.h"
#include "Building.h"

class enemyGround : public Figure
{
	bool dead;
public:
	enemyGround();
	void move(Building(*p_building)[3]);
	void operator --();
	bool isDead();
};

