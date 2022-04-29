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

	for (int i = 0; i < numList.size() - 1; i++)
	{
		std::cout << numList[i] << "\n";
	}

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
	DrawGrid();

	DrawRandomList(numList);


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
		numList[i] = rand() % 100;
	}
}

void Game::DrawRandomList(std::vector<int>& numList)
{

	static int offset = 5;
	static int width = 5;
	static int height = 10;


	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	

	for (int i = 0; i < numList.size() - 1; i++)
	{
		SDL_RenderDrawLine(renderer, offset+ (i *width), 0, offset + (i * width), numList[i] * 10);
	}

	
}

void Game::DrawGrid() const
{
	static int dimension = 10;
	static int height = 200;
	static int width = 200;
	static int offsetX = 0;
	static int offsetY = 0;

	//for (int y = offsetY * dimension; y <= (height+ offsetY) * dimension; y++)
	//{
	//	for (int x = offsetX * dimension; x <= (width + offsetX) * dimension; x++)
	//	{
	//		if (y % dimension == 0 || x % dimension == 0)
	//		{
	//			SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
	//			SDL_RenderDrawPoint(*renderer, x, y);
	//		}
	//	}
	//}

	SDL_SetRenderDrawColor(renderer, 75, 75, 75, 255);

	for (int y = dimension * offsetY; y <= (dimension + offsetY) * height; y += dimension)
	{

		SDL_RenderDrawLine(renderer, dimension * offsetX, y, (dimension + offsetX) * width, y);
		for (int x = dimension * offsetX; x <= (dimension + offsetX) * width; x += dimension)
		{
			SDL_RenderDrawLine(renderer, x, dimension * offsetY, x, (dimension + offsetY) * height);
		}
	}


}