/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "Nongine.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{

	Nongine *engine = new Nongine(SCREEN_WIDTH, SCREEN_HEIGHT, "title");
	engine->loop();
	return 0;
}