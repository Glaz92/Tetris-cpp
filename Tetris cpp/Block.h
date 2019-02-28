#pragma once
#include <array>
#include "Brick.h"

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
	virtual void setPosition(int x, int y) = 0;
};

