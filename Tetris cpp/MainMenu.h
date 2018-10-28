#pragma once
#include "GameState.h"

class MainMenu : public GameState
{
private:
	static MainMenu * mainMenu;

	MainMenu();
	~MainMenu();

public:
	static MainMenu * get();

	void run();

};