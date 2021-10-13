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
	window = SDL_CreateWindow("Test Application", 500, 100, 800, 600, SDL_WINDOW_OPENGL);
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
	
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		}

	//	if (sdlEvent.type == SDL_KEYDOWN)
	//	{
	//		KeyboardDown = true;

	//		//std::cout << "\nKeydown pressed(physical key code-scancode-): "<< sdlEvent.key.keysym.scancode<<"\n";
	//		//std::cout << "\nKeydown pressed(virtual key code-sym-): " << sdlEvent.key.keysym.sym << "\n";

	///*		fprintf(stderr,
	//			"\n\nKeyboard: key pressed  in window %d: scancode 0x%08X = %s, keycode 0x%08X = %s",
	//			sdlEvent.key.windowID,
	//			sdlEvent.key.keysym.scancode,
	//			SDL_GetScancodeName(sdlEvent.key.keysym.scancode),
	//			sdlEvent.key.keysym.sym, SDL_GetKeyName(sdlEvent.key.keysym.sym));*/

	//		//std::cout << "\nKeyPress: " << sdlEvent.key.windowID << " " << sdlEvent.key.keysym.scancode << "  " << sdlEvent.key.keysym.sym <<"  "<< SDL_GetKeyName(sdlEvent.key.keysym.sym) << "\n";

	//		//Debug Button Presses
	//		//std::cout << "\nKeyPress: " << SDL_GetKeyName(sdlEvent.key.keysym.sym) << "\n";



	//		
	//	}

	//	if (sdlEvent.type == SDL_KEYUP)
	//	{
	//		KeyboardDown = false;
	//	}


	}

	

}

void Game::Update()
{
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_RETURN]) {
		printf("<RETURN> is pressed.\n");
	}
	if (keyState[SDL_SCANCODE_RIGHT] && keyState[SDL_SCANCODE_UP]) {
		printf("Right and Up Keys Pressed.\n");
	}

	if (keyState[SDL_SCANCODE_RIGHT])
	{
		//std::cout << "\nKeyPress: " << SDL_GetKeyName(sdlEvent.key.keysym.sym) << "\n";
		player.rect.x += 0.1f;

	}
	if (keyState[SDL_SCANCODE_LEFT])
	{
		player.rect.x -= 0.1f;
	}
	//player.rect.x += 0.1f;



}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	player.Draw(renderer);


	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
