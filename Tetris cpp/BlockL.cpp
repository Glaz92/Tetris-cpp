#include "BlockL.h"

BlockL::BlockL()
	: state{ 0 }
{
}

BlockL::~BlockL()
{
}

void BlockL::rotate()
{
	switch (state)
	{
	case 0:
		bricks[3].moveUp(); bricks[3].moveUp();
		bricks[0].moveRight(); bricks[0].moveDown();
		bricks[2].moveLeft(); bricks[2].moveUp();
		state = 1;
		break;
	case 1:
		bricks[3].moveLeft(); bricks[3].moveLeft();
		bricks[0].moveLeft(); bricks[0].moveUp();
		bricks[2].moveRight(); bricks[2].moveDown();
		state = 2;
		break;
	case 2:
		bricks[3].moveDown(); bricks[3].moveDown();
		bricks[0].moveRight(); bricks[0].moveDown();
		bricks[2].moveLeft(); bricks[2].moveUp();
		state = 3;
		break;
	case 3:
		bricks[3].moveRight(); bricks[3].moveRight();
		bricks[0].moveLeft(); bricks[0].moveUp();
		bricks[2].moveRight(); bricks[2].moveDown();
		state = 0;
		break;
	}
}

void BlockL::derotate()
{
	rotate();
	rotate();
	rotate();
}

void BlockL::setPosition(int x, int y)
{
	bricks[0].setPosition(20 + brickSize * x + 1, brickSize * y + 20 + 1);
	bricks[1].setPosition(20 + brickSize * x + 1, brickSize * (y + 1) + 20 + 1);
	bricks[2].setPosition(20 + brickSize * x + 1, brickSize * (y + 2) + 20 + 1);
	bricks[3].setPosition(20 + brickSize * (x + 1) + 1, brickSize * (y + 2) + 20 + 1);
}
