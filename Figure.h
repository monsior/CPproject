#pragma once
#include "Field.h"

class Figure : public sf::Drawable
{
public:
	Figure();
	~Figure() = default;
	virtual void selectFigure(Field(*p_field)[8][8], sf::Vector2i mousePos);
	void setPosition(float t_X, float t_Y);
	bool isActive();
	void makeInactive();
	void makeActive();
	friend class meleeGroundMech;
	sf::Uint8 Dark = 150;
	int getPositionX();
	int getPositionY();
private:
	bool active;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
protected:
	bool isNeighbour(int x, int y, int n_X, int n_Y); 
	sf::Sprite sprite;
	sf::Texture texture;
};