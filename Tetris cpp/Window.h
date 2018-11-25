#pragma once
#include <SFML/Graphics.hpp>

#define WINDOW (*Window::get())

class Window
{
private:
	static Window * window;
	sf::RenderWindow renderWindow;

	Window();
	~Window();

public:
	static sf::RenderWindow * get();
};

