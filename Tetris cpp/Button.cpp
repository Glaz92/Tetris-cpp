#include "Button.h"

Button::Button(std::string str, sf::Vector2f position)
	: text(str,ConstElements::get()->font, fontSize), shape(buttonSize)
{
	text.setPosition(position);
	text.setFillColor(sf::Color::Black);
	shape.setPosition(position.x,position.y+4);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Black);
	shape.setFillColor(sf::Color::White);
}

Button::~Button()
{
}

void Button::draw()
{
	WINDOW.draw(shape);
	WINDOW.draw(text);
}
