#pragma once
#include <SDL.h>
#include <string>

using namespace std;

class Nongine
{
public:
	Nongine(int width, int height,char *title);
	~Nongine();

	bool init(int width, int height, char* title);
	bool loadImage(string pathName);
	void loop();

	SDL_Window* gWindows;
	SDL_Surface* gScreenSurface;
	SDL_Surface* gLoadSurface;
	bool running;

private:
	void inputHandler();
	SDL_Event events;
};

