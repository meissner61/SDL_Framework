#include "Game.h"

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;

	SDL_Quit();
}

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
	//Create SDL Renderer
	/*renderer = SDL_CreateRenderer(window, -1, 1);*/

	//SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	isRunning = true;

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == nullptr)
	{
		fatalError("SDL_GL Context could not be created");
	}

	GLenum error = glewInit();

	if (error != GLEW_OK)
	{
		fatalError("Could not init glew");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f,0.0f,1.0f,1);
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

		case SDL_MOUSEMOTION:
			std::cout << sdlEvent.motion.x << ' ' << sdlEvent.motion.y << std::endl;
			break;
		}
		
	}
}

void Game::Update()
{

}

void Game::Render()
{
	//SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	//SDL_RenderClear(renderer);


	//SDL_RenderPresent(renderer);

	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	///////////////////////////////
	//IMMEDIATE MODE OPENGL////////
	///////////////////////////////
	glEnableClientState(GL_COLOR_ARRAY);

	glBegin(GL_TRIANGLES);
	glColor3f(1,0,0);
	glVertex2f(-1,-1);
	glVertex2f(0, -1);
	glVertex2f(0, 0);
	glEnd();


	SDL_GL_SwapWindow(window);
}

void Game::Destroy()
{
	//SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
