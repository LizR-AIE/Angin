#include "UITesting.h"
#include <iostream>
#include <Window.h>
#include <SDL_opengl.h>
#include <Gizmos.h>
#include "glm\ext.hpp"

Game * Game::m_game = nullptr;

UITesting::UITesting()
{
	Gizmos::create();
	orthoView = glm::lookAt(glm::vec3(0, 0, -1), glm::vec3(0), glm::vec3(0, 1, 0));
	orthoProjection = glm::ortho(-640.f, 640.f, -320.f, 320.f, 0.1f, 1000.f);
	perspView = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	perspProjection = glm::perspective(glm::pi<float>() * 0.25f, 16/9.f, 0.1f, 1000.f);
}

UITesting::~UITesting()
{
	Gizmos::destroy();
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
		}				
		Gizmos::clear();
		
		Update(deltaTime);
		Render();
				
		Gizmos::draw(perspProjection, perspView);
		Gizmos::draw2D(orthoProjection * orthoView);

		SDL_GL_SwapWindow(Window::Get()->GetWindow());
	}
}

void UITesting::Update(float a_deltaTime)
{
	Gizmos::add2DAABBFilled(glm::vec2(580, 260), glm::vec2(50, 50), glm::vec4(1, 0, 1, 1));
	Gizmos::addSphere(glm::vec3(0, 0, 0), 1.0f, 32, 32, glm::vec4(1, 1, 1, 1));
}

void UITesting::Render()
{
	Gizmos::addTransform(glm::mat4(1));
	glm::vec4 white(1);
	glm::vec4 black(0, 0, 0, 1);
	for (int i = 0; i <= 20; ++i) {
		Gizmos::addLine(glm::vec3(-10 + i, 0, 10),
			glm::vec3(-10 + i, 0, -10),
			i == 10 ? white : black);
		Gizmos::addLine(glm::vec3(10, 0, -10 + i),
			glm::vec3(-10, 0, -10 + i),
			i == 10 ? white : black);
	}

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