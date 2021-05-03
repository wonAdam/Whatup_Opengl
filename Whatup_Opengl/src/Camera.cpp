#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(Transform transform)
	: GameObject("Camera", transform)
{
}

Camera::Camera(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject("Camera", position, rotation, scale)
{
}

Camera::~Camera()
{
}

void Camera::Update(float deltaTime)
{
}

glm::mat4 Camera::GetViewMatrix()
{
	glm::mat4 model = _transform.GetModelMatrix();
	glm::mat4 view = glm::inverse(model);

	return view;
}

glm::mat4 Camera::GetProjMatrix()
{
	return glm::perspective(glm::radians(fov), 800.0f / 600.0f, near, far);;
}
