#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "MainMenu.h"
#include <vector>

constexpr auto MAIN_MENU = 0;
constexpr auto GAME = 1;

#define STATIC_ITEM (*StaticItem::get())

enum class GAME_STATE {mainMenu, game};

class StaticItem
{
private:
	static StaticItem * item;

	StaticItem();
	~StaticItem();

public:
	static StaticItem * get();

private:
	std::vector<GameState*> gameState;

public:
	sf::Font font;
	int state;

	GameState * getGameState();
};

