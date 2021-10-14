#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include "Object.h"
#include <vector>

enum class GameState
{
	PLAY,
	EXIT
};

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
	bool KeyboardDown = false;
	SDL_Event sdlEvent;

	Object player = { 100,100,20,20 };
	Object objTest1;


	//std::vector<Object> objArray;

	Object objects[10];

};


#endif GAME_H
