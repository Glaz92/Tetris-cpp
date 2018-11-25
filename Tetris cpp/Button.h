#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "ConstElements.h"
#include "Window.h"

constexpr auto fontSize = 30;
#define buttonSize sf::Vector2f(180,40)

class Button
{
private:
	sf::Text text;
	sf::RectangleShape shape;

public:
	Button(std::string str, sf::Vector2f position);
	~Button();

public:
	void draw();
};

