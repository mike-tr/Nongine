#include "Nongine.h"

Nongine::Nongine(int width, int height, string title)
{
	running = init(width, height, title);
	gTexture = loadImage("textures/circle.bmp");
}

Nongine::~Nongine()
{
	SDL_FreeSurface(gTexture);
	gTexture = NULL;
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}

bool Nongine::init(int width, int height, string title)
{
	bool success = true;
	gWindow = NULL;
	gScreenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow(title.c_str(), 
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			width, height, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

SDL_Surface* Nongine::loadImage(string pathName)
{
	SDL_Surface *optimized = NULL;
	SDL_Surface *gLoadSurface = SDL_LoadBMP(pathName.c_str());
	if (gLoadSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", pathName.c_str(), SDL_GetError());
		return NULL;
	}
	else {
		optimized = SDL_ConvertSurface(gLoadSurface, gScreenSurface->format, 0);
		if (optimized == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s\n", pathName.c_str(), SDL_GetError());
			return NULL;
		}
		SDL_FreeSurface(gLoadSurface);
	}
	return optimized;
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
		else if (events.type == SDL_KEYDOWN) {
	
			SDL_Rect stretchRect;
			stretchRect.x = 0;
			stretchRect.y = 0;
			stretchRect.w = gScreenSurface->w;
			stretchRect.h = 100;
			SDL_BlitScaled(gTexture, NULL, gScreenSurface, &stretchRect);
		}
		SDL_UpdateWindowSurface(gWindow);
	}
}
