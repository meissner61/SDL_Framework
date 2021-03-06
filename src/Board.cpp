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

void Board::DrawCell(const Location& loc, Color color)
{
	rect.x = loc.x * dimension;
	rect.y = loc.y * dimension;

	SDL_SetRenderDrawColor(*renderer, color.red, color.green, color.blue, 255);
	SDL_RenderFillRect(*renderer, &rect);
}

void Board::DrawGrid() const
{
	//for (int y = offsetY * dimension; y <= (height+ offsetY) * dimension; y++)
	//{
	//	for (int x = offsetX * dimension; x <= (width + offsetX) * dimension; x++)
	//	{
	//		if (y % dimension == 0 || x % dimension == 0)
	//		{
	//			SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
	//			SDL_RenderDrawPoint(*renderer, x, y);
	//		}
	//	}
	//}

	SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);

	for (int y = dimension * offsetY; y <= (dimension + offsetY) * height; y += dimension)
	{

		SDL_RenderDrawLine(*renderer, dimension * offsetX, y, (dimension + offsetX) * width, y);
		for (int x = dimension * offsetX; x <= (dimension + offsetX) * width; x += dimension)
		{
			SDL_RenderDrawLine(*renderer, x, dimension * offsetY, x, (dimension + offsetY) * height);
		}
	}


}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= offsetX && loc.x < width+offsetX
			&& loc.y >= offsetY && loc.y < height+offsetY;
}

int Board::GetOffSetX() const
{
	return offsetX;
}

int Board::GetOffSetY() const
{
	return offsetY;
}
