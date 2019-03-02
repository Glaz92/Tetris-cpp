#include "GameBoard.h"

GameBoard::GameBoard()
	: block{ BlockFactory::createBlock() },
	  nextBlock{ BlockFactory::createBlock() },
	  score { 0 }
{
	nextBlock->setPosition(boardWidth + 2, 1);
}

GameBoard::~GameBoard()
{
}

void GameBoard::removeFullLines()
{
	std::sort(bricks.begin(), bricks.end(), [](Brick & a, Brick & b) {return a.getLine() > b.getLine(); });

	int counter = 0;
	auto begin = bricks.begin();
	auto end = bricks.end();
	int current = -2;

	for (auto it = bricks.begin(); it != bricks.end(); it++)
	{
		if (current != it->getLine())
		{
			counter = 1;
			current = it->getLine();
			begin = it;
		}
		else
		{
			end = it;
			counter++;
		}

		if (counter == boardWidth)
		{
			bricks.erase(begin, ++end);
			for (auto & brick : bricks)
			{
				if (brick.getLine() < current)
					brick.moveDown();
			}
			score += 10;
			removeFullLines();
			break;
		}
	}
}

void GameBoard::moveBlockDown()
{
	block->moveDown();
	if (block->checkCollision(bricks))
	{
		block->moveUp();
		bricks.insert(bricks.end(), block->getBricks().begin(), block->getBricks().end());

		block = nextBlock;
		nextBlock = BlockFactory::createBlock();
		nextBlock->setPosition(boardWidth + 2,1);
		block->setPosition(3, 1);
	}
}

void GameBoard::moveBlockUp()
{
	block->moveUp();
}

void GameBoard::moveBlockRight()
{
	block->moveRight();
	if (block->checkCollision(bricks))
		block->moveLeft();
}

void GameBoard::moveBlockLeft()
{
	block->moveLeft();
	if (block->checkCollision(bricks))
		block->moveRight();
}

void GameBoard::rotateBlock()
{
	block->rotate();
	if (block->checkCollision(bricks))
		block->derotate();
}

void GameBoard::draw()
{
	block->draw();
	nextBlock->draw();
	for (auto brick : bricks)
	{
		brick.draw();
	}
}

int GameBoard::getScore()
{
	return score;
}
