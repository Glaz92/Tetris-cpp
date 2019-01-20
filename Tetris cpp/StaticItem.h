#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "MainMenu.h"
#include "Game.h"
#include <vector>
#include <map>

enum class State { MainMenu, Game };

class StaticItem
{
private:
	StaticItem();
	~StaticItem();

public:
	static StaticItem & get();

private:
	std::map<State, GameState*> gameState;

public:
	State state;

	GameState & getGameState();
};

constexpr auto GetStaticItem = &StaticItem::get;