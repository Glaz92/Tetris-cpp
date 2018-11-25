#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "MainMenu.h"
#include <vector>
#include <map>

enum class State { MainMenu, Game };

#define STATIC_ITEM (*StaticItem::get())

class StaticItem
{
private:
	static StaticItem * item;

	StaticItem();
	~StaticItem();

public:
	static StaticItem * get();

private:
	std::map<State, GameState*> gameState;

public:
	State state;

	GameState * getGameState();
};

