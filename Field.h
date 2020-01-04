#pragma once
#include <SFML/Graphics.hpp>
class Field : public sf::Drawable
{
public:
	Field();
	~Field() = default;
	void setPosition(float t_X, float t_Y);
	void makeFieldActive();
	void makeFieldInRange();
	void makeFieldInactive();
	sf::Vector2f getPosition();
	bool possibleMove;
	void makeWater();
	std::string getType();
	void setType(std::string type);
	bool inRange;
private: 
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	std::string fieldType;
protected:
	sf::Texture texture;
	sf::Sprite sprite;
};