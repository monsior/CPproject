#include "meleeGroundMech.h"
#include <iostream>

meleeGroundMech::meleeGroundMech()
{
	texture.loadFromFile("mech.png");
	sprite.setTexture(texture);
}

bool canMove() 
{
	//std::cout << meleeGroundMech::figure.sprite;
	return true;
}