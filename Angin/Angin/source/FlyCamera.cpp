#include "FlyCamera3D.h"
#include "InputHandler.h"

FlyCamera3D::FlyCamera3D()
{

}

FlyCamera3D::FlyCamera3D(	const float a_fieldOfView,
							const float a_aspectRatio,
							const float a_near,
							const float a_far)
{
	setPerspective(a_fieldOfView, a_aspectRatio, a_near, a_far);
}

FlyCamera3D::~FlyCamera3D()
{
	
}

void FlyCamera3D::update(const float a_deltaTime)
{
	/*
	controls and apply the correct transforms to the camera’s transform, 
	then you would calculate the inverse of the transform for the updated view
	*/

	if(InputHandler::Get()->IsKeyDown(KEY::KEY_A))
	{
		transform = glm::translate(transform, glm::vec3(-1, 0, 0));
	}
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_D))
	{
		transform = glm::translate(transform, glm::vec3( 1, 0, 0));
	}
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_S))
	{
		transform = glm::translate(transform, glm::vec3(0, 0, 1));
	}
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_W))
	{
		transform = glm::translate(transform, glm::vec3(0, 0, -1));
	}
}