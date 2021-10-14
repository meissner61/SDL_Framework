#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "Board.h"
#include <random>

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


	Board brd;
	std::mt19937 rng;
};


#endif GAME_H
