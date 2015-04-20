#pragma once

#include "glm\glm.hpp"
#include "glm\ext.hpp"

class Camera
{
public:
	Camera()
	{
		m_transform			= glm::mat4();
		m_view				= glm::mat4();
		m_projection		= glm::mat4();
		m_projectionView	= glm::mat4();

		m_fieldOfView = 0.f;
		m_aspectRatio = 0.f;
		m_near = 0.f;
		m_far = 0.f;
	}
	~Camera(){}

	virtual void update(float deltaTime) = 0;

	//void setPerspective(float fieldOfView, float aspectRatio, float near, float far)
	void setPerspective(float fieldOfView /*= glm::pi<float>() * 0.25f*/, float aspectRatio = (16.f / 9.f), float near = 0.1f, float far = 1000.f)
	{
		m_fieldOfView = fieldOfView;
		m_aspectRatio = aspectRatio;
		m_near = near;
		m_far = far;

		m_projection = glm::perspective(m_fieldOfView, m_aspectRatio, m_near, m_far);
	}

	void setLookAt(const glm::vec3 &from, const glm::vec3 &to, const glm::vec3 &up)
	//void setLookAt(const glm::vec3 &from, const glm::vec3 &to = glm::vec3(0), const glm::vec3 &up = glm::vec3(0, 1, 0))
	{
		m_view = glm::lookAt(from, to, up);
		m_transform = glm::inverse(m_view);
	}

	void setPosition(const glm::vec3 &position)
	{
		m_transform[0][3] = position.x;
		m_transform[1][3] = position.y;
		m_transform[2][3] = position.z;

		m_view = glm::inverse(m_transform);
	}

	glm::mat4 getWorldTransform()
	{
		return m_transform;
	}

	glm::mat4 getView()
	{
		return m_view;
	}

	glm::mat4 getProjection()
	{
		return m_projection;
	}

	glm::mat4 getProjectionView()
	{
		return m_projectionView;
	}

private:
	void updateProjectionViewTransform()
	{
		m_view = glm::inverse(m_transform);
		m_projectionView = m_view * m_projection;
	}

	glm::mat4 m_transform;

	glm::mat4 m_view;
	glm::mat4 m_projection;
	glm::mat4 m_projectionView;

	float m_fieldOfView;
	float m_aspectRatio;
	float m_near;
	float m_far;
};