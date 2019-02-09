#include "Block.h"



Block::Block()
{
	bricks[0].setPosition(20 + brickSize * 3 + 1, 20 + 1);
	bricks[1].setPosition(20 + brickSize * 4 + 1, 20 + 1);
	bricks[2].setPosition(20 + brickSize * 3 + 1, 20 + brickSize + 1);
	bricks[3].setPosition(20 + brickSize * 4 + 1, 20 + brickSize + 1);
}

Block::~Block()
{
}

void Block::draw()
{
	for (auto & brick : bricks)
	{
		brick.draw();
	}
}

void Block::moveDown()
{
	for (auto & brick : bricks)
	{
		brick.moveDown();
	}
}

void Block::moveUp()
{
	for (auto & brick : bricks)
	{
		brick.moveUp();
	}
}

void Block::moveLeft()
{
	for (auto & brick : bricks)
	{
		brick.moveLeft();
	}
}

void Block::moveRight()
{
	for (auto & brick : bricks)
	{
		brick.moveRight();
	}
}

std::array<Brick, 4> & Block::getBricks()
{
	return bricks;
}

bool Block::checkCollision(std::vector<Brick> otherBricks)
{
	for (auto & brick : otherBricks)
	{
		for (auto & b : bricks)
		{
			if (b.checkCollision(brick))
				return true;
		}
	}

	if (otherBricks.size() < 1)
	{
		for (auto & b : bricks)
		{
			if (b.checkCollision(Brick()))
				return true;
		}
	}

	return false;
}
