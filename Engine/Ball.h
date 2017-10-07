#pragma once
#include "Graphics.h"
#include "Dais.h"

class Ball
{
public:
	Ball(Graphics& graphics);
	void initVars(int in_x, int in_y, int in_speed);
	void DrawBall();
	void Update(Dais& dais);
	int GetTop() const;
	int GetRight() const;
	int GetBottom() const;
	int GetLeft() const;
	void ChangeDir(char d);
private:
	Graphics& gfx;
	int x;
	int y;
	int speed;
	int vx;
	int vy;
	static constexpr int width = 10;
	static constexpr int height = 10;
	Color c = Colors::Red;
	bool colidedLeft = false;
	bool colidedRight = false;
	bool isGameOver = false;
};