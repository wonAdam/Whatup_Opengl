#pragma once

#include <string>
#include <glm/glm.hpp>

#include "Transform.h"

class Game;

class GameObject
{
public:
	Transform _transform;
	std::string _name;
	int _updatePriority;

public:
	GameObject(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
	GameObject(std::string name, Transform transform);
	GameObject(const GameObject& rhs) = delete;
	virtual ~GameObject();

public:
	virtual void Update(float deltaTime) = 0;
	virtual void LateUpdate(float deltaTime) = 0;
	virtual void Render(float deltaTime) = 0;
};

