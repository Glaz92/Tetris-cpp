#pragma once
#include <SFML/Graphics.hpp>

class ConstElements
{
private:
	static ConstElements * constElements;

	ConstElements();
	~ConstElements();

public:
	sf::Font font;
	static ConstElements * get();
};

