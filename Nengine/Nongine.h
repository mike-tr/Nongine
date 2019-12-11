#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Input.h"

using namespace std;

class Nongine
{
public:
	Nongine(int width, int height, string title);
	~Nongine();

	bool init(int width, int height, string title);
	SDL_Surface* loadImage(string pathName);
	void loop();

	Input *input;
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
	SDL_Surface* gTexture;
	bool running;

private:
	void inputHandler();
	SDL_Event events;
};

