#pragma once

#include <glm/glm.hpp>

class GameObject
{
public:
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

public:
	GameObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	GameObject(const GameObject& rhs) = delete;
	virtual ~GameObject();

public:
	virtual void Update(float deltaTime) = 0;
	glm::mat4 GetModelMatrix();

};

