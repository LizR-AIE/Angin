#pragma once
#include <Game.h>

#include "glm\glm.hpp"

#include <Camera3D.h>

class UITesting : public Game
{
public:
	UITesting();
	virtual ~UITesting();
	
	static void Create();
	static void Destroy();
	static UITesting * Get();
	
protected:
	virtual void Update(float deltaTime);
	virtual void Render();

	glm::mat4 orthoProjection;
	glm::mat4 orthoView;
	glm::mat4 perspProjection;
	glm::mat4 perspView;

	Camera3D* camera;
};