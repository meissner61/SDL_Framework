#pragma once
#include <SDL/SDL.h>
#include "Location.h"

class Board
{
public:
	Board(SDL_Renderer** renderer);
	void DrawCell(Location& loc);


private:

	static constexpr int dimension = 20;
	static constexpr int width = 10;
	static constexpr int height = 10;

	SDL_Rect rect;

	SDL_Renderer** renderer;
	//Location loc;
};