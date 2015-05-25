#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

#include "glm\mat3x3.hpp"
#include "glm\mat4x4.hpp"
#include "glm\vec3.hpp"
#include "glm\vec4.hpp"
#include "glm\gtx\quaternion.hpp"

class BaseCamera
{
public:
	ANGIN_API BaseCamera();
	ANGIN_API ~BaseCamera();

	ANGIN_API virtual void update(const float deltaTime);
	ANGIN_API void lookAt(const glm::vec3 & from, const glm::vec3 & to, const glm::vec3 & up);

	ANGIN_API void setPosition(const glm::vec3 & position);

	ANGIN_API glm::mat4 getWorldTransform();
	ANGIN_API glm::mat4 getView();
	ANGIN_API glm::mat4 getProjection();
	ANGIN_API glm::mat4 getProjectionView();
	
protected:
	glm::vec3 position;
	glm::quat rotation;
	glm::vec4 scale;
	glm::mat4 transform;
	glm::mat4 projection;
	glm::mat4 view;
	
	float near;
	float far;
};

