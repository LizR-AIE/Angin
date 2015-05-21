#include "Camera2D.h"
#include "glm\ext.hpp"

Camera2D::Camera2D()
{
	left	= 0.f;
	right	= 0.f;
	top		= 0.f;
	bottom	= 0.f;
}

Camera2D::Camera2D(	const float a_left, const float a_right, 
					const float a_top,  const float a_bottom, 
					const float a_near, const float a_far)
{
	left	= a_left;
	right	= a_right;
	top		= a_top;
	bottom	= a_bottom;
	near	= a_near;
	far		= a_far;

	view = glm::lookAt(glm::vec3(0, 0, -1), glm::vec3(0), glm::vec3(0, 1, 0));
	projection = glm::ortho(a_left, a_right, a_bottom, a_top, a_near, a_far);
}

Camera2D::~Camera2D(){}
