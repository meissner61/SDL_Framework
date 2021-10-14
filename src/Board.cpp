#include "Board.h"

Board::Board(SDL_Renderer** renderer)
	:
	renderer(renderer)
	
{
	rect.w = dimension;
	rect.h = dimension;
}

void Board::DrawCell(Location& loc, int r, int g, int b)
{
	rect.x = loc.x * dimension;
	rect.y = loc.y * dimension;

	SDL_SetRenderDrawColor(*renderer, r, g, b, 255);
	SDL_RenderFillRect(*renderer, &rect);

}
