#include "MainMenu.h"

MainMenu::MainMenu()
	: startGame("Start Game",sf::Vector2f(50,50)), settings("Settings", sf::Vector2f(50, 100)), exit("Exit", sf::Vector2f(50, 150))
{
}

MainMenu::~MainMenu()
{
}

MainMenu & MainMenu::get()
{
	static MainMenu mainMenu;

	return mainMenu;
}

void MainMenu::run()
{
	buttonsActions();
	draw();
}

void MainMenu::draw()
{
	startGame.draw();
	settings.draw();
	exit.draw();
}

void MainMenu::buttonsActions()
{
	if (startGame.isClick())
		GetStaticItem().state = State::Game;

	settings.isClick();

	if (exit.isClick())
		GetWindow().close();
}
