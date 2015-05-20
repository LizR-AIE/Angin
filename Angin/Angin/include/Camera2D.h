#pragma once

#include "glm\glm.hpp"

class Camera2D
{
public:
	Camera2D();
	Camera2D(float left, float right, float top, float bottom, float near, float far);
	~Camera2D();

private:
	glm::mat3 transform;
	glm::mat4 projection;
	glm::mat4 view;
	float left;
	float right;
	float top;
	float bottom;
	float near;
	float far;
};

