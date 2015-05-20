#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif


#include "glm\glm.hpp"
#include "glm\ext.hpp"

class Camera3D
{
public:
	ANGIN_API Camera3D()
	{
		m_transform			= glm::mat4(1);
		m_view				= glm::mat4(1);
		m_projection		= glm::mat4(1);
		m_projectionView	= glm::mat4(1);

		m_fieldOfView	= 0.f;
		m_aspectRatio	= 0.f;
		m_near			= 0.f;
		m_far			= 0.f;
	}
	~Camera3D(){}

	ANGIN_API virtual void update(float deltaTime)
	{
		updateProjectionViewTransform();
	};

	//void setPerspective(float fieldOfView, float aspectRatio, float near, float far)
	ANGIN_API void setPerspective(float fieldOfView /*= glm::pi<float>() * 0.25f*/, float aspectRatio = (16.f / 9.f), float near = 0.1f, float far = 1000.f)
	{
		m_fieldOfView	= fieldOfView;
		m_aspectRatio	= aspectRatio;
		m_near			= near;
		m_far			= far;

		m_projection = glm::perspective(m_fieldOfView, m_aspectRatio, m_near, m_far);
	}

	ANGIN_API void setLookAt(const glm::vec3 &from, const glm::vec3 &to, const glm::vec3 &up)
	//void setLookAt(const glm::vec3 &from, const glm::vec3 &to = glm::vec3(0), const glm::vec3 &up = glm::vec3(0, 1, 0))
	{
		m_view = glm::lookAt(from, to, up);
		m_transform = glm::inverse(m_view);
	}

	ANGIN_API void setPosition(const glm::vec3 &position)
	{
		m_transform[0][3] = position.x;
		m_transform[1][3] = position.y;
		m_transform[2][3] = position.z;

		m_view = glm::inverse(m_transform);
	}

	ANGIN_API glm::mat4 getWorldTransform()
	{
		return m_transform;
	}

	ANGIN_API glm::mat4 getView()
	{
		return m_view;
	}

	ANGIN_API glm::mat4 getProjection()
	{
		return m_projection;
	}

	ANGIN_API glm::mat4 getProjectionView()
	{
		return m_projectionView;
	}

	ANGIN_API void updateProjectionViewTransform()
	{
		m_view = glm::inverse(m_transform);
		m_projectionView = m_projection * m_view;
	}

private:
	glm::mat4 m_transform;

	glm::mat4 m_view;
	glm::mat4 m_projection;
	glm::mat4 m_projectionView;

	float m_fieldOfView;
	float m_aspectRatio;
	float m_near;
	float m_far;
};