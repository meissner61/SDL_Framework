#include "Game.h"

Game::Game()
{
	window = nullptr;
	renderer = nullptr;
	isRunning = false;
}

Game::~Game()
{

}

void Game::Initialize()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		return;
	}

	//Create Window
	window = SDL_CreateWindow("Test Application", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	//Create Renderer
	renderer = SDL_CreateRenderer(window, -1, 1);

	surface = IMG_Load("TileSet_V2.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);


	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	isRunning = true;
}

void Game::Setup()
{

}

void Game::Run()
{
	Setup();
	while (isRunning == true)
	{
		Input();
		Update();
		Render();
	}
}

void Game::Input()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}



}

void Game::Update()
{

}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 144;
	srcRect.h = 48;

	SDL_Rect destination;
	destination.x = 100;
	destination.y = 100;
	destination.w = 288;
	destination.h = 96;

	SDL_RenderCopy(renderer, texture, &srcRect, &destination);


	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
