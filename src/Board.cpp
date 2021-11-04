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

void Board::DrawGrid()
{
	for (int y = 0; y < height * dimension; y++)
	{
		for (int x = 0; x < width * dimension; x++)
		{
			if (y % dimension == 0 || x % dimension == 0)
			{
				SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
				SDL_RenderDrawPoint(*renderer, x, y);

			}

		}
	}
}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}
