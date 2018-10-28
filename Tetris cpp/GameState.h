#pragma once
class GameState
{
public:
	GameState();
	virtual ~GameState();

public:
	virtual void run() = 0;
};