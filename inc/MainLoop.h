#pragma once
#include "Window.h"
#include "StaticItem.h"

class MainLoop
{
private:
	MainLoop();
	~MainLoop();

public:
	static MainLoop & get();

	void run();
};

