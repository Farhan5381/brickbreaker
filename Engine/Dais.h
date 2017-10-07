#pragma once
#include "Graphics.h"

class Dais
{
public:
	Dais(Graphics& graphics);
	void initVars();
	void DrawDais();
	void Update( bool leftKey, bool rightKey);
	int GetTop() const;
	int GetRight() const;
	int GetBottom() const;
	int GetLeft() const;

private:
	Graphics& gfx;
	int x;
	int y;
	int speed = 4;
	static constexpr int width = 120;
	static constexpr int height = 20;
	Color c = Colors::Cyan;
};