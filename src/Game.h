#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <SDL/SDL_image.h>


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

	SDL_Surface* surface;
	SDL_Texture* texture;


};


#endif GAME_H
