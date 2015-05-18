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
		// Do stuff based on SDL_EventType
		switch (e.type)
		{

			#pragma region SDL_APP_DIDENTERBACKGROUND
			case SDL_EventType::SDL_APP_DIDENTERBACKGROUND:
			{
				
			}
			break;
#pragma endregion

			#pragma region SDL_APP_DIDENTERFOREGROUND
			case SDL_EventType::SDL_APP_DIDENTERFOREGROUND:
			{
				
			}
			break;
#pragma endregion
			case SDL_EventType::SDL_APP_LOWMEMORY:
			{

			}
			break;
			case SDL_EventType::SDL_APP_TERMINATING:
			{

			}
			break;
			case SDL_EventType::SDL_APP_WILLENTERBACKGROUND:
			{

			}
			break;
			case SDL_EventType::SDL_APP_WILLENTERFOREGROUND:
			{

			}
			break;
			case SDL_EventType::SDL_CLIPBOARDUPDATE:
			{

			}
			break;
			case SDL_EventType::SDL_CONTROLLERAXISMOTION:
			{

			}
			break;
			case SDL_EventType::SDL_CONTROLLERBUTTONDOWN:
			{

			}
			break;
			case SDL_EventType::SDL_CONTROLLERBUTTONUP:
			{

			}
			break;
			case SDL_EventType::SDL_CONTROLLERDEVICEADDED:
			{

			}
			break;
			case SDL_EventType::SDL_CONTROLLERDEVICEREMAPPED:
			{

			}
			break;
			case SDL_EventType::SDL_CONTROLLERDEVICEREMOVED:
			{

			}
			break;
			case SDL_EventType::SDL_DOLLARGESTURE:
			{

			}
			break;
			case SDL_EventType::SDL_DOLLARRECORD:
			{

			}
			break;
			case SDL_EventType::SDL_DROPFILE:
			{

			}
			break;
			case SDL_EventType::SDL_FINGERDOWN:
			{

			}
			break;
			case SDL_EventType::SDL_FINGERMOTION:
			{

			}
			break;
			case SDL_EventType::SDL_FINGERUP:
			{

			}
			break;
			case SDL_EventType::SDL_JOYAXISMOTION:
			{

			}
			break;
			case SDL_EventType::SDL_JOYBALLMOTION:
			{

			}
			break;
			case SDL_EventType::SDL_JOYBUTTONDOWN:
			{

			}
			break;
			case SDL_EventType::SDL_JOYBUTTONUP:
			{

			}
			break;
			case SDL_EventType::SDL_JOYDEVICEADDED:
			{

			}
			break;
			case SDL_EventType::SDL_JOYDEVICEREMOVED:
			{

			}
			break;
			case SDL_EventType::SDL_JOYHATMOTION:
			{

			}
			break;
			case SDL_EventType::SDL_KEYDOWN:
			{

			}
			break;
			case SDL_EventType::SDL_KEYUP:
			{

			}
			break;
			case SDL_EventType::SDL_MOUSEBUTTONDOWN:
			{

			}
			break;
			case SDL_EventType::SDL_MOUSEBUTTONUP:
			{

			}
			break;
			case SDL_EventType::SDL_MOUSEMOTION:
			{

			}
			break;
			case SDL_EventType::SDL_MOUSEWHEEL:
			{

			}
			break;
			case SDL_EventType::SDL_MULTIGESTURE:
			{

			}
			break;
			case SDL_EventType::SDL_QUIT:
			{

			}
			break;
			case SDL_EventType::SDL_RENDER_TARGETS_RESET:
			{

			}
			break;
			case SDL_EventType::SDL_SYSWMEVENT:
			{

			}
			break;
			case SDL_EventType::SDL_TEXTEDITING:
			{

			}
			break;
			case SDL_EventType::SDL_TEXTINPUT:
			{

			}
			break;
			case SDL_EventType::SDL_USEREVENT:
			{

			}
			break;
			case SDL_EventType::SDL_WINDOWEVENT:
			{

			}
			break;
		}
	}
}

void Game::UpdateDeltaTime()
{
	lastTotalTicks = thisTotalTicks;
	thisTotalTicks = SDL_GetTicks();
	deltaTime = ((float)thisTotalTicks - (float)lastTotalTicks) / 1000.f;
}