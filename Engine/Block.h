#pragma once
#include "Graphics.h"
#include "Ball.h"

class Block
{
public:
	void DrawBlock(int in_x, int in_y, Graphics& gfx );
	void Update(Ball& ball);
	int GetRows() const;
	int GetCols() const;

private:
	int x;
	int y;
	static constexpr int width = 50;
	static constexpr int height = 16;
	static constexpr int padding = 25;
	static constexpr int cellPadding = 2;
	static constexpr int rows = 13;
	static constexpr int columns = 23;
	Color c = Colors::Blue;
	bool isDestroyed = false;
};