#pragma once
#include "Camera3D.h"

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

class FlyCamera3D : public Camera3D
{
public:
	ANGIN_API FlyCamera3D();
	ANGIN_API FlyCamera3D(	const float fieldOfView, 
							const float aspectRatio, 
							const float near, 
							const float far);
	ANGIN_API ~FlyCamera3D();

	ANGIN_API virtual void update(const float deltaTime);
};