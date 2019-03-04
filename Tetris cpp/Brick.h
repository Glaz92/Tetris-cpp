#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <vector>

constexpr float brickSize = 20;
const auto brickColor = sf::Color::Red;
const auto brickOutlineColor = sf::Color::Black;

constexpr int boardWidth = 10;
constexpr int boardHeight = 18;
constexpr int boardPosition = 20;

class Brick
{
private:
	sf::RectangleShape brick;

public:
	Brick();
	~Brick();

public:
	void draw();
	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();

	void setPosition(float x, float y);
	bool checkCollision(Brick otherBrick);
	void setFillColor(const sf::Color & color);
	int getLine();
};