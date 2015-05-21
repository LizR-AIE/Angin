#include "Game.h"
Game * Game::m_game = nullptr;

#include <SDL.h>
#include <SDL_opengl.h>
#include "glm\ext.hpp"

#include "Gizmos.h"
#include "InputHandler.h"
#include "Window.h"

Game::Game()
{
	InputHandler::Create();
}

Game::~Game()
{
	InputHandler::Destroy();
}

void Game::Run()
{
	bool gQuit = false;
	SDL_Event e;

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	glEnable(GL_DEPTH_TEST);

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
				InputHandler::Get()->keyDown[(KEY)e.key.keysym.sym] = true;
				switch (e.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						gQuit = true;
						break;
					}
					default:
					{
						break;
					}
				}
			}
			else if(e.type == SDL_KEYUP)
			{
				InputHandler::Get()->keyDown[(KEY)e.key.keysym.sym] = false;
			}
		}
		Gizmos::clear();

		Update(deltaTime);
		Render();

		SDL_GL_SwapWindow(Window::Get()->GetWindow());
	}
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