#include <iostream>
#include <Window.h>
#include "UITesting.h"
#include <SDL.h>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int main(int argc, char* args[])
{
	{
		UITesting game;
		game.Run();

		//bool gQuit = false;
		//SDL_Event e;
		//
		//Window::Create(1280, 720, "UITesting");
		//
		//UITesting::Create();
		//
		//while (!gQuit)
		//{
		//	// Poll Events
		//	while (SDL_PollEvent(&e) != 0)
		//	{
		//		if (e.type == SDL_QUIT)
		//		{
		//			gQuit = true;
		//		}
		//		else if (e.type == SDL_KEYDOWN)
		//		{
		//			switch (e.key.keysym.sym)
		//			{
		//				case SDLK_ESCAPE:
		//				{
		//					gQuit = true;
		//					break;
		//				}
		//			}
		//		}
		//	}
		//
		//	// Call Game Loop
		//	UITesting::Get()->Loop();
		//}
		//
		//UITesting::Destroy();
		//
		//Window::Destroy();
	}

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}