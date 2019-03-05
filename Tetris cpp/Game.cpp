#include "Game.h"
#include <algorithm>
#include <iostream>

Game::Game()
	: board(sf::Vector2f(boardWidth * brickSize, boardHeight * brickSize)),
	  nextBrick(sf::Vector2f(brickSize * 6 + 5, brickSize * 4 + 5)),
	  scoreBoard(sf::Vector2f(brickSize * 6 + 5,30)),
	  pause(false),
	  gameSpeed(500),
	  score("0", ConstElements::get().font, 14),
	  pauseText("PAUSE",ConstElements::get().font, 30)
{
	sf::Color boardColor = sf::Color::White;
	sf::Color outlineColor = sf::Color::Black;
	float outlineThickness = 2;

	board.setOutlineThickness(outlineThickness);
	nextBrick.setOutlineThickness(outlineThickness);
	scoreBoard.setOutlineThickness(outlineThickness);

	board.setFillColor(boardColor);
	board.setOutlineColor(outlineColor);
	nextBrick.setFillColor(boardColor);
	nextBrick.setOutlineColor(outlineColor);
	scoreBoard.setFillColor(boardColor);
	scoreBoard.setOutlineColor(outlineColor);

	board.setPosition(20,20);
	nextBrick.setPosition(20+10+board.getSize().x,20);
	scoreBoard.setPosition(20 + 10 + board.getSize().x, 20+10+ nextBrick.getSize().y);

	score.setFillColor(sf::Color::Black);
	score.setPosition(scoreBoard.getPosition().x + 5, scoreBoard.getPosition().y + 5);

	pauseText.setFillColor(sf::Color::Black);
	pauseText.setOrigin(pauseText.getGlobalBounds().width/2,0);
	pauseText.setPosition(board.getPosition().x + board.getGlobalBounds().width/2, board.getPosition().y + 50);
	pauseText.setOutlineThickness(1);
	pauseText.setOutlineColor(outlineColor);
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
	if(!pause) logic();
}

void Game::draw()
{
	GetWindow().draw(board);
	GetWindow().draw(nextBrick);
	GetWindow().draw(scoreBoard);

	GetWindow().draw(score);
	gameBoard.draw();

	if (pause) GetWindow().draw(pauseText);
}

void Game::control()
{
	int minTime = 100;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::P));

		pause = pause ? false : true;
	}

	if (controlTime.asMilliseconds() > minTime && !pause)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			gameBoard.rotateBlock();
			controlClock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			gameBoard.moveBlockDown();
			controlClock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			gameBoard.moveBlockLeft();
			controlClock.restart();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			gameBoard.moveBlockRight();
			controlClock.restart();
		}
	}
}

void Game::logic()
{
	if (time.asMilliseconds() > gameSpeed)
	{
		gameBoard.moveBlockDown();
		clock.restart();
	}

	gameBoard.removeFullLines();
	score.setString(std::to_string(gameBoard.getScore()));

	gameSpeed = 500 - gameBoard.getScore() / 100 * 25;
	gameSpeed = gameSpeed < 100 ? 100 : gameSpeed;
}
