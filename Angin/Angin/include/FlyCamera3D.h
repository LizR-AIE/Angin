#pragma once
#include "Camera3D.h"

class FlyCamera3D : public Camera3D
{
	FlyCamera3D();
	~FlyCamera3D();

	virtual void update(float deltaTime);
};