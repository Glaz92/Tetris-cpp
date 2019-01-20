#pragma once
#include "GameState.h"
#include "Window.h"
#include <SFML/Graphics.hpp>

constexpr float brickSize = 15;
constexpr int boardWidth = 10;
constexpr int boardHeight = 18;

class Game :
	public GameState
{
private:
	sf::RectangleShape gameBoard;
	sf::RectangleShape nextBrick;
	sf::RectangleShape scoreBoard;

	Game();
	~Game();

public:
	static Game & get();

	void run();
	void draw();
};