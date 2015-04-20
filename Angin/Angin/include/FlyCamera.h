#pragma once
#include "Camera.h"

class FlyCamera : public Camera
{
	FlyCamera();
	~FlyCamera();

	virtual void update(float deltaTime);
};