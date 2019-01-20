#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "ConstElements.h"
#include "Window.h"

constexpr auto fontSize = 30;
const sf::Vector2f buttonSize(180, 40);
const auto activeColor = sf::Color::Blue;
const auto idleColor = sf::Color::White;

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
	bool isClick();
};

