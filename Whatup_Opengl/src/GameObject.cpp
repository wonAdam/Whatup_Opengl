#include "GameObject.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

GameObject::GameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	:_position(position), _rotation(rotation), _scale(scale)
{
}

GameObject::~GameObject()
{
}

glm::mat4 GameObject::GetModelMatrix()
{
	glm::mat4 trans = glm::translate(glm::mat4(1.0f), _position);

	float radX = glm::radians(_rotation.x), radY = glm::radians(_rotation.y), radZ = glm::radians(_rotation.z);
	glm::mat4 rot = glm::eulerAngleYXZ(radY, radX, radZ);
	return trans * rot;
}
