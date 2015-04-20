#include "UITesting.h"
#include <iostream>
#include <SDL.h>
#include <Window.h>

Game * Game::m_game = nullptr;

UITesting::UITesting()
{
	bool success = true;

	SDL_Surface* hWorld = SDL_LoadBMP("helloworld.bmp");
	if (hWorld == nullptr)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "helloworld.bmp", SDL_GetError());
		success = false;
	}
	printf("Loaded Hello World BMP: %s", success ? "true" : "false");
	
	helloWorld = SDL_ConvertSurface(hWorld, Window::Get()->GetSurface()->format, NULL);
	if (helloWorld == nullptr)
	{
		printf("Unable to optimize image %s! SDL Error: %s\n", "helloworld.bmp", SDL_GetError());
	}
	SDL_FreeSurface(hWorld);
	//SDL_BlitSurface(helloWorld, nullptr, Window::Get()->GetSurface(), nullptr);
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = Window::Get()->GetWindowWidth();// SCREEN_WIDTH;
	stretchRect.h = Window::Get()->GetWindowHeight();//SCREEN_HEIGHT;
	SDL_BlitScaled(helloWorld, NULL, Window::Get()->GetSurface(), &stretchRect);
}

UITesting::~UITesting()
{
	SDL_FreeSurface(helloWorld);
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