#include "MainMenu.h"

MainMenu::MainMenu()
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
}
