#include "BlockZ.h"



BlockZ::BlockZ()
{
}


BlockZ::~BlockZ()
{
}

void BlockZ::rotate()
{
	if (horizontal)
	{
		bricks[3].moveUp(); bricks[3].moveUp();
		bricks[3].moveLeft();
		bricks[2].moveLeft();

		horizontal = false;
	}
	else
	{
		bricks[3].moveDown(); bricks[3].moveDown();
		bricks[3].moveRight();
		bricks[2].moveRight();

		horizontal = true;
	}
}

void BlockZ::derotate()
{
	rotate();
}

void BlockZ::setPosition(int x, int y)
{
	bricks[0].setPosition(20 + brickSize * (x) + 1, brickSize * y + 20 + 1);
	bricks[1].setPosition(20 + brickSize * (x + 1) + 1, brickSize * y + 20 + 1);
	bricks[2].setPosition(20 + brickSize * (x + 1)+1, brickSize * (y + 1) + 20 + 1);
	bricks[3].setPosition(20 + brickSize * (x + 2) + 1, brickSize * (y + 1) + 20 + 1);
}
