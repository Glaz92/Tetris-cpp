#pragma once
#include "GameState.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include "BlockFactory.h"
#include "GameBoard.h"
#include "ConstElements.h"

class Game :
	public GameState
{
private:
	sf::RectangleShape board;
	sf::RectangleShape nextBrick;
	sf::RectangleShape scoreBoard;

	GameBoard gameBoard;
	
	bool pause;
	
	sf::Clock clock;
	sf::Time time;
	sf::Clock controlClock;
	sf::Time controlTime;

	int gameSpeed;
	sf::Text score;

public:
	Game();
	~Game();

	void run();

private:
	void draw();
	void control();
	void logic();
};