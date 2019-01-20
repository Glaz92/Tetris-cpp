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

	MainMenu();
	~MainMenu();

public:
	static MainMenu & get();

	void run();

private:
	void draw();
	void buttonsActions();

};