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
	float translationSpeed = 10.f * a_deltaTime;
	float rotationSpeed = 0.05f * a_deltaTime;

	if(InputHandler::Get()->IsKeyDown(KEY::KEY_A))
	{ position += glm::vec3(-translationSpeed, 0, 0); }
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_D))
	{ position += glm::vec3( translationSpeed, 0, 0); }
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_S))
	{ position += glm::vec3(0, 0, translationSpeed); }
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_W))
	{ position += glm::vec3(0, 0, -translationSpeed); }
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_Q))
	{ position += glm::vec3(0, translationSpeed, 0); }
	if (InputHandler::Get()->IsKeyDown(KEY::KEY_E))
	{ position += glm::vec3(0, -translationSpeed, 0);}

	transform = glm::translate(transform, position);
	position = glm::vec3(0, 0, 0);

	// MATRIX
	// If right mouse is down
	
	if (InputHandler::Get()->IsMouseDown(MB::MB_RITE))
	{
		glm::vec2 mouseMovement = InputHandler::Get()->GetRelativeMouseMovement() * rotationSpeed;
		glm::vec3 axisX = (glm::vec3)transform[0];

		transform = glm::rotate(transform, mouseMovement.x, glm::vec3(0.f,1.f,0.f));
		transform = glm::rotate(transform, mouseMovement.y, axisX);
	}
	

	// QUAT
	/*
	if (InputHandler::Get()->IsMouseDown(MB::MB_RITE))
	{
		glm::vec2 mouseMovement = InputHandler::Get()->GetRelativeMouseMovement() * rotationSpeed;
		
		glm::quat rot = glm::quat();
		rot *= glm::angleAxis(mouseMovement.x, glm::vec3(0.f, 1.f, 0.f));
		rot *= glm::angleAxis(mouseMovement.y, glm::vec3(1.f, 0.f, 0.f));
		
		rot  = glm::normalize(rot);
		
		transform = transform * glm::toMat4(rot);
	}
	*/
}