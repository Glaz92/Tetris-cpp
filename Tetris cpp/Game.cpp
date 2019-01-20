#include "Game.h"

Game::Game()
	: gameBoard(sf::Vector2f(boardWidth * brickSize + boardWidth - 1, boardHeight * brickSize+boardHeight - 1)),
	  nextBrick(sf::Vector2f(brickSize * 6 + 5, brickSize * 6 + 5)),
	  scoreBoard(sf::Vector2f(brickSize * 6 + 5,30))
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

Game & Game::get()
{
	static Game game;

	return game;
}

void Game::run()
{
	draw();
}

void Game::draw()
{
	GetWindow().draw(gameBoard);
	GetWindow().draw(nextBrick);
	GetWindow().draw(scoreBoard);
}
