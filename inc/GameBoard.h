#pragma once
#include "GameState.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include "BlockFactory.h"

class GameBoard
{
private:
	int score;

	std::shared_ptr<Block> block;
	std::shared_ptr<Block> nextBlock;

	std::vector<Brick> bricks;

public:
	GameBoard();
	~GameBoard();

public:
	void removeFullLines();

	void moveBlockDown();
	void moveBlockUp();
	void moveBlockRight();
	void moveBlockLeft();

	void rotateBlock();

	void draw();
	int getScore();
};