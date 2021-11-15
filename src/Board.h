#ifndef BOARD_H
#define BOARD_H
#include <SDL2/SDL.h>
#include "Location.h"
#include "Color.h"

class Board
{
public:
	Board(SDL_Renderer** renderer);
	void DrawCell(const Location& loc, int r, int g, int b);
	void DrawCell(const Location& loc, Color color);
	//void DrawCell(Location& loc,) //TODO: Make a Color class for non RGB draw cell
	void DrawGrid() const;
	int GetWidth() const;
	int GetHeight() const;
	bool IsInsideBoard(const Location& loc) const;
	int GetOffSetX() const;
	int GetOffSetY() const;


private:

	static constexpr int dimension = 20;
	static constexpr int width = 20;
	static constexpr int height = 20;
	static constexpr int offsetX = 10;
	static constexpr int offsetY = 5;

	int r = 255;
	int g = 0;
	int b = 0;

	SDL_Rect rect;

	SDL_Renderer** renderer;
	//Location loc;
};

#endif