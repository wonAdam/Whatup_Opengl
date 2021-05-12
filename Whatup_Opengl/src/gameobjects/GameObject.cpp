#include "GameObject.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

GameObject::GameObject(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: _transform(position, rotation, scale), _name(name)
{
}

GameObject::GameObject(std::string name, Transform transform)
	:  _transform(transform), _name(name)
{
}

GameObject::~GameObject()
{
}



