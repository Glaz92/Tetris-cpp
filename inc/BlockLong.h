#pragma once
#include "Block.h"

class BlockLong :
	public Block
{
private:
	bool horizontal;

public:
	BlockLong();
	~BlockLong();

public:
	virtual void rotate() override;
	virtual void derotate() override;
	virtual void setPosition(int x, int y) override;
};

