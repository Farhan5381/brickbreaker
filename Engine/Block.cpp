#include "Block.h"

void Block::DrawBlock( int in_x, int in_y, Graphics& gfx)
{
	x = in_x * width + padding + cellPadding;
	y = in_y * height + padding + cellPadding;
	if( !isDestroyed )
	{
		gfx.DrawRectDim( x, y, width - cellPadding, height - cellPadding, c );
	}
}

void Block::Update( Ball & ball )
{
	// Block sides
	int top = y;
	int right = x + width;
	int bottom = y + height;
	int left = x;

	//Check collision with Ball and check if block is destroyed then chand block status and ball direction
	if( top <= ball.GetBottom() && right >= ball.GetLeft() && bottom >= ball.GetTop() && left <= ball.GetRight() && !isDestroyed )
	{
		
		if( right == ball.GetLeft() )
		{
			ball.ChangeDir( 'r' );
		}
		else if( left == ball.GetRight() )
		{
			ball.ChangeDir( 'l' );
		}
		else
		{
			ball.ChangeDir( 'n' );
		}
		isDestroyed = true;
	}
}

int Block::GetRows() const
{
	return rows;
}

int Block::GetCols() const
{
	return columns;
}
