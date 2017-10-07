#include "Ball.h"

Ball::Ball( Graphics & graphics )
	:
	gfx(graphics)
{
}

void Ball::initVars( int in_x, int in_y, int in_speed )
{
	x = in_x - (width / 2);
	y = in_y - height - 1;
	speed = in_speed;
	vx = -speed;
	vy = -speed;
}

void Ball::DrawBall()
{
	gfx.DrawRectDim( x, y, width, height, c );
}

void Ball::Update(Dais& dais)
{
	x += vx;
	y += vy;
	if( x <= 0 )
	{
		x = 0;
		vx = speed;
	}
	if( x + width >= gfx.ScreenWidth )
	{
		x = gfx.ScreenWidth - width;
		vx = -speed;
	}
	if( y <= 0 )
	{
		y = 0;
		vy = speed;
	}
	if( y + height >= gfx.ScreenHeight )
	{
		y = gfx.ScreenHeight - height;
		vx = 0;
		vy = 0;
		isGameOver = true;
	}
	
	// Ball sides
	int top = y;
	int right = x + width;
	int bottom = y + height;
	int left = x;

	//Check collision with dais
	if( top <= dais.GetBottom() && right >= dais.GetLeft() && bottom >= dais.GetTop() && left <= dais.GetRight() )
	{
		
		if( right == dais.GetLeft() )
		{
			vx = -speed;
			vy = -speed;
		} 
		else if( left == dais.GetRight() )
		{
			vx = speed;
			vy = -speed;
		}
		else 
		{
			vy = -speed;
		}
	}
}

int Ball::GetTop() const
{
	return y;
}

int Ball::GetRight() const
{
	return x + width;
}

int Ball::GetBottom() const
{
	return y + height;
}

int Ball::GetLeft() const
{
	return x;
}

void Ball::ChangeDir(char d)
{
	if( d == 'l' )
	{
		vx = -speed;
		vy = -speed;
	}
	else if( d == 'r' )
	{
		vx = speed;
		vy = speed;
	}
	else if( vx > 0 && vy > 0 )
	{
		vy = -speed;
	}
	else if( vx < 0 && vy > 0 )
	{
		vy = -speed;
	}
	else if( vx > 0 && vy < 0 )
	{
		vy = speed;
	}
	else if( vx < 0 && vy < 0 )
	{
		vy = speed;
	}
}
