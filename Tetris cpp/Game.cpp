#include "Game.h"
#include <algorithm>
#include <iostream>

Game::Game()
	: gameBoard(sf::Vector2f(boardWidth * brickSize, boardHeight * brickSize)),
	  nextBrick(sf::Vector2f(brickSize * 6 + 5, brickSize * 6 + 5)),
	  scoreBoard(sf::Vector2f(brickSize * 6 + 5,30)),
	  pause(false),
	  block { BlockFactory::createBlock() },
	  nextBlock { BlockFactory::createBlock() },
	  gameSpeed(300)
{
	sf::Color boardColor = sf::Color::White;
	sf::Color outlineColor = sf::Color::Black;
	float outlineThickness = 2;

	gameBoard.setOutlineThickness(outlineThickness);
	nextBrick.setOutlineThickness(outlineThickness);
	scoreBoard.setOutlineThickness(outlineThickness);

	gameBoard.setFillColor(boardColor);
	gameBoard.setOutlineColor(outlineColor);
	nextBrick.setFillColor(boardColor);
	nextBrick.setOutlineColor(outlineColor);
	scoreBoard.setFillColor(boardColor);
	scoreBoard.setOutlineColor(outlineColor);

	gameBoard.setPosition(20,20);
	nextBrick.setPosition(20+10+gameBoard.getSize().x,20);
	scoreBoard.setPosition(20 + 10 + gameBoard.getSize().x, 20+10+ nextBrick.getSize().y);
}

Game::~Game()
{
}

void Game::run()
{
	time = clock.getElapsedTime();
	controlTime = controlClock.getElapsedTime();

	draw();
	control();
	logic();
}

void Game::draw()
{
	GetWindow().draw(gameBoard);
	GetWindow().draw(nextBrick);
	GetWindow().draw(scoreBoard);
	block->draw();
	for (auto brick : bricks)
	{
		brick.draw();
	}
}

void Game::control()
{
	int minTime = 50;
	if (controlTime.asMilliseconds() > minTime)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::P));

			pause = pause ? false : true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			block->moveDown();
			if (block->checkCollision(bricks))
			{
				block->moveUp();

				bricks.insert(bricks.end(), block->getBricks().begin(), block->getBricks().end());

				block = BlockFactory::createBlock();
			}
			controlClock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			block->moveLeft();
			if (block->checkCollision(bricks))
				block->moveRight();
			controlClock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			block->moveRight();
			if (block->checkCollision(bricks))
				block->moveLeft();
			controlClock.restart();
		}
	}
}

void Game::logic()
{
	if (time.asMilliseconds() > gameSpeed)
	{
		block->moveDown();
		if (block->checkCollision(bricks))
		{
			block->moveUp();
			bricks.insert(bricks.end(), block->getBricks().begin(), block->getBricks().end());

			block = BlockFactory::createBlock();
			block->setPosition(3, 0);
		}
		clock.restart();
	}

	removeFullLines();
}

void Game::removeFullLines()
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
			bricks.erase(begin,++end);
			for (auto & brick : bricks) 
			{ 
				if (brick.getLine() < current)
					brick.moveDown();
			}
			removeFullLines();
			break;
		}
	}
}
