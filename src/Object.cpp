#include "Object.h"

Object::Object(float x, float y, float width, float height)
{
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}

void Object::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRectF(renderer, &rect);
}
