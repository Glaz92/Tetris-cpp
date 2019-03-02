#pragma once
#include "Block.h"
class BlockSquare :
	public Block
{
public:
	BlockSquare();
	~BlockSquare();

public:
	virtual void rotate() override;
	virtual void derotate() override;
	virtual void setPosition(int x, int y) override;
};