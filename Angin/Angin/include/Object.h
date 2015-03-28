#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

#include <glm\mat4x4.hpp>
class Object
{
public:
	ANGIN_API Object();
	ANGIN_API ~Object();

	glm::mat4 Transform;
};