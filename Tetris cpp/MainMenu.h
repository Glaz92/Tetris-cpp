#pragma once
#include "GameState.h"
#include "Button.h"

class Button;

class MainMenu : public GameState
{
private:
	static MainMenu * mainMenu;

	Button startGame;
	Button settings;
	Button exit;

	MainMenu();
	~MainMenu();

public:
	static MainMenu * get();

	void run();

private:
	void draw();

};