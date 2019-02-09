#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "MainMenu.h"
#include "Game.h"
#include <vector>
#include <map>
#include <unordered_map>

enum class State { MainMenu, Game };

class StaticItem
{
private:
	std::unordered_map<State, std::shared_ptr<GameState>> gameState;
	StaticItem();
	~StaticItem();

public:
	static StaticItem & get();

public:
	State state;

	std::shared_ptr<GameState> getGameState();
};

constexpr auto GetStaticItem = &StaticItem::get;