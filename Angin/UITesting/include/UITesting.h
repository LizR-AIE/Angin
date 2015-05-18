#pragma once
#include <Game.h>
#include "glm\glm.hpp"
class UITesting : public Game
{
public:
	UITesting();
	virtual ~UITesting();
	
	static void Create();
	static void Destroy();
	static UITesting * Get();

	virtual void Run();

protected:
	virtual void Update(float deltaTime);
	virtual void Render();

	glm::mat4 orthoProjection;
	glm::mat4 orthoView;
	glm::mat4 perspProjection;
	glm::mat4 perspView;
};