#include "Nongine.h"

Nongine::Nongine(int width, int height, char *title)
{
	running = init(width, height, title);
	loadImage("textures/circle.bmp");
	SDL_BlitSurface(gLoadSurface, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(gWindows);
}

Nongine::~Nongine()
{
	SDL_FreeSurface(gLoadSurface);
	gLoadSurface = NULL;
	SDL_DestroyWindow(gWindows);
	SDL_Quit();
}

bool Nongine::init(int width, int height, char * title)
{
	bool success = true;
	gWindows = NULL;
	gScreenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindows = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (gWindows == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindows);
		}
	}
	return success;
}

bool Nongine::loadImage(string pathName)
{
	bool success = true;
	gLoadSurface = SDL_LoadBMP("textures/circle.bmp");
	if (gLoadSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void Nongine::loop()
{
	while (running) {
		inputHandler();
	}
}

void Nongine::inputHandler()
{
	while (SDL_PollEvent(&events) != 0) {
		if (events.type == SDL_QUIT) {
			running = false;
		}
	}
}
