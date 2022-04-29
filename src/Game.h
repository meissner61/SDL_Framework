#ifndef GAME_H
#define GAME_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <algorithm>
#include <random>
#include <vector>
#include <ctime>


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
	void BadRandom(std::vector<int> &numList);
	void DrawRandomList(std::vector<int>& numList);
	void DrawGrid() const;



private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

	int numArray[800];

	std::vector<int> numList;


};


#endif GAME_H
