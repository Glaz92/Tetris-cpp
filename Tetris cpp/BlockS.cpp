#include "BlockS.h"

BlockS::BlockS()
{
}

BlockS::~BlockS()
{
}

void BlockS::rotate()
{
	if (horizontal)
	{
		bricks[2].moveUp(); bricks[0].moveUp();
		bricks[2].moveRight();
		bricks[3].moveRight();

		horizontal = false;
	}
	else
	{
		bricks[2].moveDown(); bricks[0].moveDown();
		bricks[2].moveLeft(); 
		bricks[3].moveLeft();

		horizontal = true;
	}
}

void BlockS::derotate()
{
	rotate();
}

void BlockS::setPosition(int x, int y)
{
	bricks[0].setPosition(20 + brickSize * (x + 1) + 1, brickSize * y + 20 + 1);
	bricks[1].setPosition(20 + brickSize * (x + 2) + 1, brickSize * y + 20 + 1);
	bricks[2].setPosition(20 + brickSize * (x) + 1, brickSize * (y + 1) + 20 + 1);
	bricks[3].setPosition(20 + brickSize * (x + 1) + 1, brickSize * (y + 1) + 20 + 1);
}