#include "BlockSquare.h"

BlockSquare::BlockSquare()
{
}

BlockSquare::~BlockSquare()
{
}

void BlockSquare::rotate()
{
}

void BlockSquare::setPosition(int x, int y)
{
	bricks[0].setPosition(20 + brickSize * x + 1, brickSize * y + 20 + 1);
	bricks[1].setPosition(20 + brickSize * (x + 1) + 1, brickSize * y + 20 + 1);
	bricks[2].setPosition(20 + brickSize * x + 1, brickSize * (y + 1) + 20 + 1);
	bricks[3].setPosition(20 + brickSize * (x + 1) + 1, brickSize * (y + 1) + 20 + 1);
}
