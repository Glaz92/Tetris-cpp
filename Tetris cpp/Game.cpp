#include "Game.h"

Game::Game()
	: gameBoard(sf::Vector2f(boardWidth * brickSize, boardHeight * brickSize)),
	  nextBrick(sf::Vector2f(brickSize * 6 + 5, brickSize * 6 + 5)),
	  scoreBoard(sf::Vector2f(brickSize * 6 + 5,30)),
	  pause(false)
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

	draw();
	control();
}

void Game::draw()
{
	GetWindow().draw(gameBoard);
	GetWindow().draw(nextBrick);
	GetWindow().draw(scoreBoard);
	block.draw();
	for (auto brick : bricks)
	{
		brick.draw();
	}
}

void Game::control()
{
	int minTime = 50;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::P));

		pause = pause ? false : true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (time.asMilliseconds() > minTime)
		{
			block.moveDown();
			if (block.checkCollision(bricks))
			{
				block.moveUp();

				bricks.insert(bricks.end(), block.getBricks().begin(), block.getBricks().end());

				Block b;
				block = b;
			}
			clock.restart();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (time.asMilliseconds() > minTime)
		{
			block.moveLeft();
			if (block.checkCollision(bricks))
				block.moveRight();
			clock.restart();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (time.asMilliseconds() > minTime)
		{
			block.moveRight();
			if (block.checkCollision(bricks))
				block.moveLeft();
			clock.restart();
		}
	}
}

void Game::logic()
{
	if (time.asMilliseconds() > 200)
	{
		block.moveDown();
		if (block.checkCollision(bricks))
		{
			block.moveUp();
			bricks.insert(bricks.end(), block.getBricks().begin(), block.getBricks().end());

			Block b;
			block = b;
		}
		clock.restart();
	}
}
