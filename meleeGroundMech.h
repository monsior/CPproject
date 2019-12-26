#pragma once
#include "Figure.h"

class meleeGroundMech : public Figure
{
public:
	meleeGroundMech();
	~meleeGroundMech() = default;
	void move(sf::Vector2i pixelPos);
};