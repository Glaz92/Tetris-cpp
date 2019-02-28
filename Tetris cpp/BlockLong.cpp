#include "BlockLong.h"



BlockLong::BlockLong()
{
}


BlockLong::~BlockLong()
{
}

void BlockLong::rotate()
{
}

void BlockLong::setPosition(int x, int y)
{
	bricks[0].setPosition(20 + brickSize * x + 1, brickSize * y + 20 + 1);
	bricks[1].setPosition(20 + brickSize * (x+1) + 1, brickSize * y + 20 + 1);
	bricks[2].setPosition(20 + brickSize * (x+2) + 1, brickSize * y + 20 + 1);
	bricks[3].setPosition(20 + brickSize * (x+3) + 1, brickSize * y + 20 + 1);
}
