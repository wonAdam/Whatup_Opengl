#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include "Game.h"

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
	return glm::lookAt(_transform._position, _transform._position + _transform.GetForward(), _transform.GetUp());
}

glm::mat4 Camera::GetProjMatrix()
{
	return glm::perspective(glm::radians(fov), 800.0f / 600.0f, near, far);;
}

void Camera::Rotate(float xoffset, float yoffset)
{
	_transform._rotation += glm::vec3(yoffset * sensitiviy, xoffset * sensitiviy, 0.0f);

	_transform._rotation.x = glm::clamp(_transform._rotation.x, -89.0f, 89.0f);
	_transform._rotation.y = glm::clamp(_transform._rotation.y, -180.0f, 180.0f);
}

void Camera::Move(float xoffset, float yoffset, float zoffset)
{
	glm::vec3 displacement = _transform.GetRight() * xoffset + _transform.GetUp() * yoffset + _transform.GetForward() * zoffset;
	_transform._position += glm::vec3(displacement * Game::deltaTime * movementSpeed);
}
