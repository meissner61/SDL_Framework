#ifndef BOARD_H
#define BOARD_H
#include <SDL/SDL.h>
#include "Location.h"

class Board
{
public:
	Board(SDL_Renderer** renderer);
	void DrawCell(const Location& loc, int r, int g, int b);
	//void DrawCell(Location& loc,) //TODO: Make a Color class for non RGB draw cell
	int GetWidth();
	int GetHeight();


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

#endif