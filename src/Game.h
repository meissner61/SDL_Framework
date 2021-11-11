#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Board.h"
#include <random>
#include "Snake.h"
#include <iostream>

class Game
{

public:
	Game();
	~Game();
	void Initialize();
	void Run();
	void Input();
	void Setup();
	void Update();
	void Render();
	void Destroy();



private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool gameIsOver = false;

	int moveCounter = 0;

	SDL_Event sdlEvent;
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	Board brd;
	std::mt19937 rng;
	Snake snek;

	Location delta_loc = { 1,0 };
};


#endif GAME_H
