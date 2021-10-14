#pragma once
#include <SDL/SDL.h>
#include "Location.h"

class Board
{
public:
	Board(SDL_Renderer** renderer);
	void DrawCell(Location& loc, int r, int g, int b);


private:

	static constexpr int dimension = 20;
	static constexpr int width = 10;
	static constexpr int height = 10;

	int r;
	int g;
	int b;

	SDL_Rect rect;

	SDL_Renderer** renderer;
	//Location loc;
};