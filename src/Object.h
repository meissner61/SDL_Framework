#pragma once
#include <SDL/SDL.h>
#include <random>


class Object
{
public:
	Object();
	Object(float x, float y, float width, float height);
	void Draw(SDL_Renderer* renderer);
	void WallBounce(SDL_Window* window);


public:
	//float x;//Not needed - SDL_Rect stores x,y,w,h
	//float y;
	//int width;
	//int height;
	SDL_FRect rect;

	float speed = 0.1f;
	float velX;
	float velY;

	int r = 255;
	int g = 255;
	int b = 255;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> posDist;//position distribution
	std::uniform_int_distribution<int> colorDist;
	std::uniform_real_distribution<float> velDist;


	bool dead = false;
	bool isMoving = true;



};

