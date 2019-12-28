#pragma once
#include <SFML/Graphics.hpp>
class Field : public sf::Drawable
{
public:
	Field();
	~Field() = default;
	void setPosition(float t_X, float t_Y);
	void makeFieldActive();
	void makeFieldInactive();
	sf::Vector2f getPosition();
	bool possibleMove;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};