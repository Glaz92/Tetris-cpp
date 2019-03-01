#include "BlockLong.h"



BlockLong::BlockLong()
	: horizontal(true)
{
}


BlockLong::~BlockLong()
{
}

void BlockLong::rotate()
{
	if (horizontal)
	{
		bricks[0].moveUp(); bricks[0].moveUp();
		bricks[0].moveRight(); bricks[0].moveRight();
		bricks[1].moveUp();
		bricks[1].moveRight();
		bricks[3].moveDown();
		bricks[3].moveLeft();

		horizontal = false;
	}
	else
	{
		bricks[0].moveDown(); bricks[0].moveDown();
		bricks[0].moveLeft(); bricks[0].moveLeft();
		bricks[1].moveDown();
		bricks[1].moveLeft();
		bricks[3].moveUp();
		bricks[3].moveRight();

		horizontal = true;
	}
}

void BlockLong::setPosition(int x, int y)
{
	bricks[0].setPosition(20 + brickSize * x + 1, brickSize * y + 20 + 1);
	bricks[1].setPosition(20 + brickSize * (x+1) + 1, brickSize * y + 20 + 1);
	bricks[2].setPosition(20 + brickSize * (x+2) + 1, brickSize * y + 20 + 1);
	bricks[3].setPosition(20 + brickSize * (x+3) + 1, brickSize * y + 20 + 1);
}
