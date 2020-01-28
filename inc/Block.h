#pragma once
#include <array>
#include "Brick.h"

const auto blockLongColor = sf::Color::Red;
const auto blockLColor = sf::Color::Yellow;
const auto blockJColor = sf::Color::Magenta;
const auto blockZColor = sf::Color::Blue;
const auto blockSColor = sf::Color::Cyan;
const auto blockSquareColor = sf::Color::Green;
const auto blockTColor = sf::Color(120,120,120);

class Block
{
protected:
	std::array<Brick, 4> bricks;

public:
	Block();
	virtual ~Block();

public:
	void draw();
	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();

	std::array<Brick, 4> & getBricks();

	bool checkCollision(std::vector<Brick> otherBricks);

	virtual void rotate() = 0;
	virtual void derotate() = 0;
	virtual void setPosition(int x, int y) = 0;
};

