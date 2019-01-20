#include "StaticItem.h"

StaticItem::StaticItem()
	: state(State::MainMenu)
{
//	gameState.emplace(std::make_pair(State::MainMenu,&MainMenu::get()));
//	gameState.emplace(std::make_pair(State::Game,Game::get()));
}


StaticItem::~StaticItem()
{
}

StaticItem & StaticItem::get()
{
	StaticItem item;

	return item;
}

GameState & StaticItem::getGameState()
{
	switch (state)
	{
	case State::MainMenu:
		return MainMenu::get();
		break;
	case State::Game:
		return Game::get();
		break;
	default:
		break;
	}
}
