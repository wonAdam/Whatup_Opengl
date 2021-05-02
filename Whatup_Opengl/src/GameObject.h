#pragma once
#include <glm/glm.hpp>
class GameObject
{
public:
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

	GameObject();
	virtual ~GameObject();
	void Update();
};

