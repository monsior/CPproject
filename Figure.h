#pragma once
#include "Field.h"

class Figure : public sf::Drawable
{
public:
	Figure();
	~Figure() = default;
	void setPosition(float t_X, float t_Y);
	bool isActive();
	void makeInactive();
	void makeActive();
	sf::Uint8 Dark = 150;
	int getPositionX();
	int getPositionY();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	void changeFieldType(Field(*p_field)[8][8]);
protected:
	bool isNeighbour(int x, int y, int n_X, int n_Y); 
	sf::Sprite sprite;
	sf::Texture texture;
	bool active;
};
