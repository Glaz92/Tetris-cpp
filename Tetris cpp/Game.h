#pragma once
#include "GameState.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include "BlockFactory.h"

class Game :
	public GameState
{
private:
	sf::RectangleShape gameBoard;
	sf::RectangleShape nextBrick;
	sf::RectangleShape scoreBoard;
	
	bool pause;

	std::shared_ptr<Block> block;
	std::shared_ptr<Block> nextBlock;

	std::vector<Brick> bricks;

	sf::Clock clock;
	sf::Time time;
	sf::Clock controlClock;
	sf::Time controlTime;

	int gameSpeed;

public:
	Game();
	~Game();

	void run();

private:
	void draw();
	void control();
	void logic();
	void removeFullLines();
};