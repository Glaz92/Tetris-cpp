#pragma once
#include "Block.h"
class BlockLong :
	public Block
{
public:
	BlockLong();
	~BlockLong();

public:
	virtual void rotate() override;
	virtual void setPosition(int x, int y) override;
};

