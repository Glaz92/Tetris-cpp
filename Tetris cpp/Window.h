#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Window
{
private:
	sf::RenderWindow renderWindow;

	Window();
	~Window();

public:
	static sf::RenderWindow & get();
};

constexpr auto GetWindow = &Window::get;