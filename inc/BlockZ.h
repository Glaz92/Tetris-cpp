#pragma once
#include "Block.h"
class BlockZ :
	public Block
{
private:
	bool horizontal;

public:
	BlockZ();
	~BlockZ();

public:
	virtual void rotate() override;
	virtual void derotate() override;
	virtual void setPosition(int x, int y) override;
};

