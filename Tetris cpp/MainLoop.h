#pragma once
#include "Window.h"
#include "StaticItem.h"

class MainLoop
{
private:
	static MainLoop * mainLoop;

	MainLoop();
	~MainLoop();

public:
	static MainLoop * get();

	void run();
};

