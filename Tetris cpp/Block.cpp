#include "Block.h"

Block::Block()
{
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
