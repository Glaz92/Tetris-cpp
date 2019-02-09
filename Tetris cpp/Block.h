#pragma once
#include <array>
#include "Brick.h"

class Block
{
protected:
	std::array<Brick, 4> bricks;

public:
	Block();
	~Block();

public:
	void draw();
	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();

	std::array<Brick, 4> & getBricks();

	bool checkCollision(std::vector<Brick> otherBricks);
};

