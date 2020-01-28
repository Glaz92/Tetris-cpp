#pragma once
#include "Block.h"

class BlockS :
	public Block
{
private:
	bool horizontal;

public:
	BlockS();
	~BlockS();

public:
	virtual void rotate() override;
	virtual void derotate() override;
	virtual void setPosition(int x, int y) override;
};

