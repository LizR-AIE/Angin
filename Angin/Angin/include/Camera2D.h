#pragma once
#include "BaseCamera.h"

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif


#include "glm\mat3x3.hpp"
#include "glm\mat4x4.hpp"

class Camera2D : public BaseCamera
{
public:
	ANGIN_API Camera2D();
	ANGIN_API Camera2D(	const float left, const float right, 
						const float top,  const float bottom, 
						const float near, const float far);
	ANGIN_API ~Camera2D();

private:
	float left;
	float right;
	float top;
	float bottom;

};

