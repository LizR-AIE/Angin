#include "Camera2D.h"
#include "glm\ext.hpp"

Camera2D::Camera2D()
{
	transform = glm::mat3(1);
}

Camera2D::Camera2D(float a_left, float a_right, float a_top, float a_bottom, float a_near, float a_far)
{
	view = glm::lookAt(glm::vec3(0, 0, -1), glm::vec3(0), glm::vec3(0, 1, 0));
	projection = glm::ortho(a_left, a_right, a_bottom, a_top, a_near, a_far);
}

Camera2D::~Camera2D()
{

}
