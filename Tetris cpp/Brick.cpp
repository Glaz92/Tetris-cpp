#include "Brick.h"

Brick::Brick()
	: brick(sf::Vector2f(brickSize - 2, brickSize - 2))
{
	brick.setOutlineThickness(1);
	brick.setOutlineColor(brickOutlineColor);
	brick.setFillColor(brickColor);
}

Brick::~Brick()
{
}

void Brick::draw()
{
	GetWindow().draw(brick);
}

void Brick::moveDown()
{
	brick.move(0, brickSize);
}

void Brick::moveUp()
{
	brick.move(0, -brickSize);
}

void Brick::moveLeft()
{
	brick.move(-brickSize,0);
}

void Brick::moveRight()
{
	brick.move(brickSize, 0);
}

void Brick::setPosition(float x, float y)
{
	brick.setPosition(x,y);
}

bool Brick::checkCollision(Brick otherBrick)
{
	sf::Vector2f vec1 = otherBrick.brick.getPosition();
	sf::Vector2f vec2 = brick.getPosition();

	if (vec1.x + 2 > vec2.x && vec1.x - 2 < vec2.x)
		if (vec1.y + 2 > vec2.y && vec1.y - 2 < vec2.y)
			return true;

	if (vec2.y > boardPosition + boardHeight * brickSize)
		return true;

	if (vec2.x < boardPosition || vec2.x > boardPosition + boardWidth * brickSize)
		return true;

	return false;
}
