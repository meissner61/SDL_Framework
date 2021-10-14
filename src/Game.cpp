#include "Game.h"
#include <string>

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
	window = SDL_CreateWindow("Test Application", 500, 100, 800, 600, SDL_WINDOW_RESIZABLE);
	//SDL_WINDOW_OPENGL
	//Create Renderer
	renderer = SDL_CreateRenderer(window, -1, 1);

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	isRunning = true;

	const char* platform;

	platform = SDL_GetPlatform();

	std::cout << platform;
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
	float x;
	float y;
	
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_MOUSEMOTION:
			//std::cout << sdlEvent.motion.x << ' ' << sdlEvent.motion.y << std::endl;
			break;
		case SDL_MOUSEBUTTONDOWN:
			std::cout << sdlEvent.button.x << ' ' << sdlEvent.button.y << std::endl;
			x = sdlEvent.button.x;
			y = sdlEvent.button.y;
			std::cout << "OBJ1( " << objects[1].rect.x << objects[1].rect.y << ")\n";
			//Object obj = { x,y ,20,20};
			//objArray.emplace_back(x,y,20,20);

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

	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_RIGHT])
	{
		//std::cout << "\nKeyPress: " << SDL_GetKeyName(sdlEvent.key.keysym.sym) << "\n";
		player.rect.x += player.speed;

	}
	if (keyState[SDL_SCANCODE_LEFT])
	{
		player.rect.x -= player.speed;
	}
	if (keyState[SDL_SCANCODE_UP])
	{
		player.rect.y -= player.speed;
	}
	if (keyState[SDL_SCANCODE_DOWN])
	{
		player.rect.y += player.speed;
	}
	

}

void Game::Update()
{

	
	for (int i = 0; i < OBJECTS; i++)
	{
		objects[i].WallBounce(window);
	}


}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	player.Draw(renderer);
	objTest1->Draw(renderer);


	for (int i = 0; i < OBJECTS; i++)
	{
		objects[i].Draw(renderer);
	}


	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	//ScreenShot Code
	SDL_Surface* sshot = SDL_CreateRGBSurface(0, 800, 600, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
	SDL_SaveBMP(sshot, "screenshot.bmp");
	SDL_FreeSurface(sshot);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
