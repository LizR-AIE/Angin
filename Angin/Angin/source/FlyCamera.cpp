#include "FlyCamera3D.h"
#include "InputHandler.h"
#include "Game.h"

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
	float translationSpeed = 10.f * a_deltaTime;
	float rotationSpeed = 0.5f * a_deltaTime;

	if(InputHandler::Get()->IsKeyDown(KEY::KEY_A))
	{
		position += glm::vec3(-translationSpeed, 0, 0);
		//transform = glm::translate(transform, glm::vec3(-translationSpeed, 0, 0));
	}
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_D))
	{
		position += glm::vec3( translationSpeed, 0, 0);
		//transform = glm::translate(transform, glm::vec3( translationSpeed, 0, 0));
	}
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_S))
	{
		position += glm::vec3(0, 0, translationSpeed);
		//transform = glm::translate(transform, glm::vec3(0, 0, translationSpeed));
	}
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_W))
	{
		position += glm::vec3(0, 0, -translationSpeed);
		//transform = glm::translate(transform, glm::vec3(0, 0, -translationSpeed));
	}

	// If right mouse is down
	if (InputHandler::Get()->IsMouseDown(MB::MB_RITE))
	{
		glm::vec2 mouseMovement = InputHandler::Get()->GetRelativeMouseMovement() * rotationSpeed;
		
		static float time = 0;
		time += a_deltaTime;
		
		glm::quat newRot = rotation;
						  		
		//newRot = glm::rotate(newRot, mouseMovement.y * rotationSpeed, glm::vec3(-1.f, 0.f, 0.f));
		//newRot = glm::rotate(newRot, mouseMovement.x * rotationSpeed, glm::vec3( 0.f,-1.f, 0.f));
		//newRot += glm::vec3();
		
		rotation = glm::slerp(rotation, newRot, time);

		//transform = glm::rotate(transform, mouseMovement.y * rotationSpeed, glm::vec3(-1.f, 0.f, 0.f));		
		//transform = glm::rotate(transform, mouseMovement.x * rotationSpeed, glm::vec3( 0.f,-1.f, 0.f));
	}
	transform = glm::translate(position) * glm::toMat4(rotation);
}