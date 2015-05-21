#include "BaseCamera.h"

#include "glm\glm.hpp"
#include "glm\ext.hpp"

BaseCamera::BaseCamera()
{
	transform = glm::mat4(1);
	projection = glm::mat4(1);
	view = glm::mat4(1);

	near = 0.1f;
	far = 1000.f;
}

BaseCamera::~BaseCamera(){}

void BaseCamera::update(const float a_deltaTime){}

void BaseCamera::lookAt(const glm::vec3 & a_from, 
						const glm::vec3 & a_to, 
						const glm::vec3 & a_up)
{
	view = glm::lookAt(a_from, a_to, a_up);
	transform = glm::inverse(view);
}

void BaseCamera::setPosition(const glm::vec3 & a_position)
{
	transform[0][3] = a_position.x;
	transform[1][3] = a_position.y;
	transform[2][3] = a_position.z;

	view = glm::inverse(transform);
}

glm::mat4 BaseCamera::getWorldTransform()	{ return transform; }
glm::mat4 BaseCamera::getView()				{ return view; }
glm::mat4 BaseCamera::getProjection()		{ return projection; }

glm::mat4 BaseCamera::getProjectionView()
{
	view = glm::inverse(transform);
	return projection * view;
}