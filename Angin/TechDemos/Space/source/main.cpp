#include <iostream>
#include <Window.h>
#include "Space.h"
#include <SDL.h>
#include <SDL_opengl.h>

#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#endif

int main(int argc, char *argv[])
{
	{
		bool gQuit = false;
		SDL_Event e;

		Window::Create(1600, 720, "Space");

		Space::Create();

		while (!gQuit)
		{
			glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
			glEnable(GL_DEPTH_TEST);
			// Poll Events
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					gQuit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
						case SDLK_ESCAPE:
						{
							gQuit = true;
							break;
						}
					}
				}
			}

			// Call Game Loop
			Space::Get()->Loop();
		}

		Space::Destroy();

		Window::Destroy();
	}

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}