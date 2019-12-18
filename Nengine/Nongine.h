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
	SDL_Texture* loadTexture(string pathName);
	void loop();

	Input *input;
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Texture* gTexture;
	bool running;

private:
	void inputHandler();
	SDL_Event events;
};

