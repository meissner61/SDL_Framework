#include "Game.h"

Game::Game()
	:
	brd(&renderer),
	rng(std::random_device()()),
	snek(Location{0,0})
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
	moveCounter++;
	if (moveCounter == 1000)
	{
		snek.MoveBy(Location{ 1,0 });
		moveCounter = 0;
	}
	
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	//std::uniform_int_distribution<int> r(0, 255);
	//std::uniform_int_distribution<int> g(0, 255);
	//std::uniform_int_distribution<int> b(0, 255);



	//for (int y = 0; y < brd.GetHeight(); y++)
	//{
	//	for (int x = 0; x < brd.GetWidth(); x++)
	//	{
	//		int red = r(rng);
	//		int green = g(rng);
	//		int blue = b(rng);
	//		Location loc = { x,y };
	//		brd.DrawCell(loc, red,green,blue);
	//	}
	//}

	snek.Draw(brd);


	

	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
