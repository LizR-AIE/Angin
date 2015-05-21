#pragma once
#include "BaseCamera.h"

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif


#include "glm\glm.hpp"
#include "glm\ext.hpp"

class Camera3D : public BaseCamera
{
public:
	ANGIN_API Camera3D();
	ANGIN_API Camera3D(	const float fieldOfView, 
						const float aspectRatio, 
						const float near, 
						const float far);
	ANGIN_API ~Camera3D();
	
	//void setPerspective(float fieldOfView, float aspectRatio, float near, float far)
	ANGIN_API void setPerspective(	const float fieldOfView /*= glm::pi<float>() * 0.25f*/, 
									const float aspectRatio = (16.f / 9.f), 
									const float near = 0.1f, 
									const float far = 1000.f);
		
private:
	float fieldOfView;
	float aspectRatio;
	
};