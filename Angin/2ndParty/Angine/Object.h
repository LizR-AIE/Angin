#pragma once
#include <glm\mat4x4.hpp>
class Object
{
public:
	Object();
	~Object();

	glm::mat4 Transform;
};