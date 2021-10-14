#include "Object.h"

Object::Object()
	:
	rng(rd()),
	posDist(0, 780),
	colorDist(0, 255),
	velDist(-2.0, 2.0)
{
	rect.x = posDist(rng);
	rect.y = posDist(rng) - 200;
	rect.w = 5;
	rect.h = 5;

	r = colorDist(rng);
	g = colorDist(rng);
	b = colorDist(rng);

	velX = velDist(rng);
	velY = velDist(rng);
}

Object::Object(float x, float y, float width, float height)
{
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
}

void Object::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRectF(renderer, &rect);
}

void Object::WallBounce(SDL_Window* window)
{
	if (rect.x <= 0)
	{
		rect.x = 1.0f;
		(velX) *= (-1);
	}
	else if ((rect.x + rect.w) >= SDL_GetWindowSurface(window)->w)
	{
		rect.x = (SDL_GetWindowSurface(window)->w - rect.w);
		(velX) *= (-1);
	}
	else if (rect.y <= 0)
	{
		rect.y = 1.0f;
		(velY) *= (-1);
	}
	else if ((rect.y + rect.h) >= SDL_GetWindowSurface(window)->h)
	{
		rect.y = (SDL_GetWindowSurface(window)->h - rect.h);
		(velY) *= (-1);
	}
	rect.x += speed * velX;
	rect.y += speed * velY;
}