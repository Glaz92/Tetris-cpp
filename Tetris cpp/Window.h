#pragma once
#include <SFML/Graphics.hpp>

#define WINDOW (*Window::get())

class Window
{
private:
	static Window * window;

	Window();
	~Window();

public:
	static Window * get();

	void someFunc();

};

