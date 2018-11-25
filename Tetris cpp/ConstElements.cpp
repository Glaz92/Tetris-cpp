#include "ConstElements.h"

ConstElements * ConstElements::constElements = nullptr;

ConstElements::ConstElements()
{
	font.loadFromFile("data/font/font.ttf");
}


ConstElements::~ConstElements()
{
}

ConstElements * ConstElements::get()
{
	if (constElements == nullptr)
		constElements = new ConstElements();

	return constElements;
}
