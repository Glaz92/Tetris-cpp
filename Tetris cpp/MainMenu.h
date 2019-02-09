#pragma once
#include "GameState.h"
#include "Button.h"
#include "StaticItem.h"

class Button;

class MainMenu : public GameState
{
private:
	Button startGame;
	Button settings;
	Button exit;

public:
	MainMenu();
	~MainMenu();

	void run();

private:
	void draw();
	void buttonsActions();

};