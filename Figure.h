#pragma once
#include "Field.h"

class Figure : public sf::Drawable
{
public:
	Figure();
	~Figure() = default;
	void selectFigure();
	void setPosition(float t_X, float t_Y);
	sf::Sprite sprite;
	sf::Texture texture;
	bool isActive();
	void makeInactive();
	friend class meleeGroundMech;
	//void setTexture();
private:
	bool active; 
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};
