#include "Game.h"
#include <iostream>

Game::Game()
	:numList(100)
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
	window = SDL_CreateWindow("Test Application", 100, 100, 800, 600, SDL_WINDOW_RESIZABLE);
	//Create Renderer
	renderer = SDL_CreateRenderer(window, -1, 1);

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	isRunning = true;
}

void Game::Setup()
{
	BadRandom(numList);

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

		case SDL_KEYDOWN:
			if (sdlEvent.key.keysym.sym == SDLK_SPACE)
			{
				int width = 0;
				width = SDL_GetWindowSurface(window)->w;
				std::cout << width << "\n";

				for (int i = 0; i < numList.size() - 1; i++)
				{
					std::cout << numList[i] << std::endl;
				}
			}
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


	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::BadRandom(std::vector<int>& numList)
{

	srand(time(NULL));

	for (int i = 0; i < numList.size() - 1; i++)
	{
		numList[i] = rand() % 1000;
	}
}

void Game::DrawRandomList(std::vector<int>& numList)
{
	
}
