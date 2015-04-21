#include "UITesting.h"
#include <iostream>
#include <Window.h>
#include <SDL.h>
#include <SDL_opengl.h>

Game * Game::m_game = nullptr;

UITesting::UITesting()
{
	
}

UITesting::~UITesting()
{
	SDL_FreeSurface(helloWorld);
	SDL_GL_DeleteContext(Window::Get()->GetGLContext());
}

void UITesting::Create()
{
	if (m_game == nullptr)
		m_game = new UITesting();
}

void UITesting::Loop()
{
	float deltaTime = (float)SDL_GetTicks();
	
	Update(deltaTime);

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
	Render();
	
	SDL_GL_SwapWindow(Window::Get()->GetWindow());
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