#include "Dais.h"

Dais::Dais( Graphics & graphics )
	:
	gfx( graphics )
{
}

void Dais::initVars()
{
	x = ( gfx.ScreenWidth - width ) / 2;
	y = 449;
}

void Dais::DrawDais()
{
	gfx.DrawRectDim( x, y, width, height, c );
}

void Dais::Update( bool leftKey, bool rightKey )
{
	if( leftKey )
	{
		x -= speed;
	}
	if( rightKey )
	{
		x += speed;
	}

	// Making sure that the dais is within the boundary of the screen
	if( x <= 0 )
	{
		x = 0;
	}
	if( x + width >= gfx.ScreenWidth )
	{
		x = gfx.ScreenWidth - width;
	}
}

int Dais::GetTop() const
{
	return y;
}

int Dais::GetRight() const
{
	return x + width;
}

int Dais::GetBottom() const
{
	return y + height;
}

int Dais::GetLeft() const
{
	return x;
}

