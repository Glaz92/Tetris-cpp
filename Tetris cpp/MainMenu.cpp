#include "MainMenu.h"

MainMenu * MainMenu::mainMenu = nullptr;

MainMenu::MainMenu()
	: startGame("Start Game",sf::Vector2f(50,50)), settings("Settings", sf::Vector2f(50, 100)), exit("Exit", sf::Vector2f(50, 150))
{
}

MainMenu::~MainMenu()
{
}

MainMenu * MainMenu::get()
{
	if (mainMenu == nullptr)
		mainMenu = new MainMenu();

	return mainMenu;
}

void MainMenu::run()
{
	draw();
}

void MainMenu::draw()
{
	startGame.draw();
	settings.draw();
	exit.draw();
}
