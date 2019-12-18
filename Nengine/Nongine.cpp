#include "Nongine.h"

Nongine::Nongine(int width, int height, string title)
{
	running = init(width, height, title);
	if (!running) {
		SDL_Delay(10000);
		return;
	}
	gTexture = loadTexture("textures/blob.png");
}

Nongine::~Nongine()
{
	//SDL_FreeSurface(gTexture);
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;
	IMG_Quit();
	SDL_Quit();
}

bool Nongine::init(int width, int height, string title)
{
	bool success = true;
	gWindow = NULL;
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
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

SDL_Texture* Nongine::loadTexture(string path)
{
	SDL_Texture *texture = NULL;

	SDL_Surface *loadSurface = IMG_Load(path.c_str());
	if (loadSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		return NULL;
	}
	else {
		texture = SDL_CreateTextureFromSurface(gRenderer, loadSurface);
		if (texture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			return NULL;
		}

		SDL_FreeSurface(loadSurface);
	}
	return texture;
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
			stretchRect.w = 100;
			stretchRect.h = 100;
			
		}
		SDL_RenderClear(gRenderer);
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
		SDL_RenderPresent(gRenderer);
	}
}
