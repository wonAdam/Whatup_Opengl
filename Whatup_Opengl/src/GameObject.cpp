#include "GameObject.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

glm::vec3 GameObject::GetForward()
{
	glm::vec3 v(0.0f, 0.0f, 1.0f); // identity orientation;
	glm::mat4 rot = glm::eulerAngleYXZ(
		glm::radians(_rotation.y), 
		glm::radians(_rotation.x), 
		glm::radians(_rotation.z));
	v = rot * glm::vec4(v, 0.0f);
	return glm::normalize(v);
}

glm::vec3 GameObject::GetUp()
{
	glm::vec3 v(0.0f, 1.0f, 0.0f); // identity orientation;
	glm::mat4 rot = glm::eulerAngleYXZ(
		glm::radians(_rotation.y),
		glm::radians(_rotation.x),
		glm::radians(_rotation.z));
	v = rot * glm::vec4(v, 0.0f);
	return glm::normalize(v);
}

glm::vec3 GameObject::GetRight()
{
	glm::vec3 v(1.0f, 0.0f, 0.0f); // identity orientation;
	glm::mat4 rot = glm::eulerAngleYXZ(
		glm::radians(_rotation.y),
		glm::radians(_rotation.x),
		glm::radians(_rotation.z));
	v = rot * glm::vec4(v, 0.0f);
	return glm::normalize(v);
}

GameObject::GameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: _position(position), _rotation(rotation), _scale(scale)
{
}

GameObject::~GameObject()
{
}
