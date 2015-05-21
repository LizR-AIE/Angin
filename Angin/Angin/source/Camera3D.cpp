#include "Camera3D.h"

Camera3D::Camera3D()
{
	fieldOfView = 0.f;
	aspectRatio = 0.f;
}

Camera3D::Camera3D(	const float a_fieldOfView,
					const float a_aspectRatio,
					const float a_near,
					const float a_far) : BaseCamera()
{
	setPerspective(a_fieldOfView, a_aspectRatio, a_near, a_far);
}

Camera3D::~Camera3D(){}

void Camera3D::setPerspective(	const float a_fieldOfView = glm::pi<float>() * 0.25f, 
								const float a_aspectRatio, 
								const float a_near, 
								const float a_far)
{
	fieldOfView	= a_fieldOfView;
	aspectRatio	= a_aspectRatio;
	near		= a_near;
	far			= a_far;

	projection = glm::perspective(fieldOfView, aspectRatio, near, far);
}