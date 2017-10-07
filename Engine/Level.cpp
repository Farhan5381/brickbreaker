#include "Level.h"

void Level::initBlockLocations()
{
	int index = 0;
	for( int i = 0; i < LevelCols; ++i )
	{
		for( int j = 0; j < LevelRows; ++j )
		{
			x[index] = i;
			y[index] = j;
			++index;
		}
	}
}

void Level::DrawBlocks(Graphics& gfx)
{
	for( int i = 0; i < size; i++ )
	{
		blocks[i].DrawBlock( x[i], y[i], gfx);
	}
}

void Level::Update(Ball& ball)
{
	for( int i = 0; i < size; i++ )
	{
		blocks[i].Update(ball);
	}
}
