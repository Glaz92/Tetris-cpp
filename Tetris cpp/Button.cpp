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
	GetWindow().draw(shape);
	GetWindow().draw(text);
}

bool Button::isClick()
{
	shape.setFillColor(idleColor);
	sf::Vector2f position = shape.getPosition();
	sf::Vector2f size = shape.getSize();

	if (sf::Mouse::getPosition(GetWindow()).x > position.x && sf::Mouse::getPosition(GetWindow()).x < position.x + size.x)
		if (sf::Mouse::getPosition(GetWindow()).y > position.y && sf::Mouse::getPosition(GetWindow()).y < position.y + size.y)
		{
			shape.setFillColor(activeColor);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
				if (sf::Mouse::getPosition(GetWindow()).x > position.x && sf::Mouse::getPosition(GetWindow()).x < position.x + size.x)
					if (sf::Mouse::getPosition(GetWindow()).y > position.y && sf::Mouse::getPosition(GetWindow()).y < position.y + size.y)
						return true;
			}
		}


	return false;
}
