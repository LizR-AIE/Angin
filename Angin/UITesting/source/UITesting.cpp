#include "UITesting.h"
#include <iostream>
#include <SDL.h>
#include <Window.h>

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

void UITesting::Loop()
{
	float deltaTime = SDL_GetTicks();
	Update(deltaTime);
	Render();

	SDL_UpdateWindowSurface(Window::Get()->GetWindow());
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