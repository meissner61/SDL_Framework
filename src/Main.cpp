#include <iostream>
#include <SDL\SDL.h>
#include <chrono>
#include <ctime>
#include "Game.h"
#include <GL\glew.h>



int main(int arc, char* argv [])
{

	struct tm newtime;

	SDL_Init(SDL_INIT_EVERYTHING);

	std::cout << "Test output\n";

	std::cout << "\x1B[32m"<<"Hello World" "\033[0m"<< std::endl;

	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string output(30, '\0');
	//std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));
	localtime_s(&newtime, &now);
	std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", &newtime);
	std::cout << output<<std::endl;


	Game game;

	game.Initialize();
	game.Run();
	game.Destroy();


	return 0;
}