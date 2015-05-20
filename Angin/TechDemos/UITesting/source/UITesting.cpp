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

	camera = new Camera3D();
	camera->setLookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	camera->setPerspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
}

UITesting::~UITesting()
{
	Gizmos::destroy();
	delete camera;
}

void UITesting::Create()
{
	if (m_game == nullptr)
		m_game = new UITesting();
}

void UITesting::Update(float a_deltaTime)
{
	camera->update(a_deltaTime);
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
	Gizmos::draw(camera->getProjectionView());
	Gizmos::draw2D(orthoProjection * orthoView);
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