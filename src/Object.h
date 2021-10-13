#pragma once
#include <SDL/SDL.h>


class Object
{
public:
	Object(float x, float y, float width, float height);
	void Draw(SDL_Renderer* renderer);


public:
	//float x;//Not needed - SDL_Rect stores x,y,w,h
	//float y;
	//int width;
	//int height;
	SDL_FRect rect;

	float speed;
	float velX;
	float velY;


	bool dead = false;
	bool isMoving = true;



};

