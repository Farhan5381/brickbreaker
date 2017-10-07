#pragma once
#include "Graphics.h"
#include "Block.h"
#include "Ball.h"

class Level
{
public:
	void initBlockLocations();
	void DrawBlocks(Graphics& gfx);
	void Update(Ball& ball);

private:
	static constexpr int LevelRows = 5;
	static constexpr int LevelCols = 13;
	static constexpr int size = LevelRows * LevelCols;
	Block blocks[size];
	int x[size];
	int y[size];
};
