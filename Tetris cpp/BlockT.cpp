#include "BlockT.h"



BlockT::BlockT()
	: state{ 0 }
{
	for (auto & brick : bricks)
	{
		brick.setFillColor(blockTColor);
	}
}


BlockT::~BlockT()
{
}

void BlockT::rotate()
{
	switch (state)
	{
	case 0:
		bricks[2].moveLeft(); bricks[2].moveUp();
		state = 1;
		break;
	case 1:
		bricks[3].moveRight(); bricks[3].moveUp();
		state = 2;
		break;
	case 2:
		bricks[0].moveDown(); bricks[0].moveRight();
		state = 3;
		break;
	case 3:
		bricks[2].moveRight(); bricks[2].moveDown();
		bricks[3].moveLeft(); bricks[3].moveDown();
		bricks[0].moveUp(); bricks[0].moveLeft();
		state = 0;
		break;
	}
}

void BlockT::derotate()
{
//	rotate();
//	rotate();
//	rotate();
}

void BlockT::setPosition(int x, int y)
{
	bricks[0].setPosition(20 + brickSize * x + 1, brickSize * y + 20 + 1);
	bricks[1].setPosition(20 + brickSize * (x + 1) + 1, brickSize * y + 20 + 1);
	bricks[2].setPosition(20 + brickSize * (x + 2) + 1, brickSize * y + 20 + 1);
	bricks[3].setPosition(20 + brickSize * (x + 1) + 1, brickSize * (y + 1) + 20 + 1);
}
