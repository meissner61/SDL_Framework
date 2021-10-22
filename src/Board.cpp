#include "Board.h"

Board::Board(SDL_Renderer** renderer)
	:
	renderer(renderer)
	
{
	rect.w = dimension;
	rect.h = dimension;
}

void Board::DrawCell(const Location& loc, int r, int g, int b)
{
	rect.x = loc.x * dimension;
	rect.y = loc.y * dimension;

	SDL_SetRenderDrawColor(*renderer, r, g, b, 255);
	SDL_RenderFillRect(*renderer, &rect);

}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}
