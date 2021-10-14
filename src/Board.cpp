#include "Board.h"

Board::Board(SDL_Renderer** renderer)
	:
	renderer(renderer)
	
{
	rect.w = width;
	rect.h = height;
}

void Board::DrawCell(Location& loc)
{
	rect.x = loc.x;
	rect.y = loc.y;

	SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(*renderer, &rect);

}
