#include "Game.h"
Game * Game::m_game = nullptr;

#include <SDL.h>

Game::Game()
{
	
}

Game::~Game()
{

}

void Game::Create()
{
	if (m_game == nullptr)
		m_game = new Game();
}

void Game::Destroy()
{
	if (m_game != nullptr) 
	{
		delete m_game;
		m_game = nullptr;
	}
}

void Game::Run()
{

}

void Game::PollEvents()
{
	static SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		// Do stuff based on SDL events
	}
}

void Game::UpdateDeltaTime()
{
	lastTotalTicks = thisTotalTicks;
	thisTotalTicks = SDL_GetTicks();
	deltaTime = ((float)thisTotalTicks - (float)lastTotalTicks) / 1000.f;
}