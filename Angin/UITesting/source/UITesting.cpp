#include "UITesting.h"
#include <iostream>
#include <Window.h>
#include <SDL_opengl.h>

Game * Game::m_game = nullptr;

UITesting::UITesting()
{

}

UITesting::~UITesting()
{
		
}

void UITesting::Create()
{
	if (m_game == nullptr)
		m_game = new UITesting();
}

void UITesting::Run()
{
	bool gQuit = false;
	SDL_Event e;

	glClearColor(1, 0, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glUseProgram(0);
	while (!gQuit)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		UpdateDeltaTime();

		// PollEvents();
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
		
		Update(deltaTime);

		Render();

		SDL_GL_SwapWindow(Window::Get()->GetWindow());
	}
}

void UITesting::Update(float a_deltaTime)
{

}

void UITesting::Render()
{

}

void UITesting::Destroy()
{
	if (m_game != nullptr)
	{
		delete m_game;
		m_game = nullptr;
	}
}

UITesting * UITesting::Get()
{
	return (UITesting*)(Game::m_game);
}