#pragma once
#include "GameState.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include "Block.h"

class Game :
	public GameState
{
private:
	sf::RectangleShape gameBoard;
	sf::RectangleShape nextBrick;
	sf::RectangleShape scoreBoard;
	
	bool pause;

	Block block;

	std::vector<Brick> bricks;

	sf::Clock clock;
	sf::Time time;

public:
	Game();
	~Game();

	void run();

private:
	void draw();
	void control();
	void logic();
};