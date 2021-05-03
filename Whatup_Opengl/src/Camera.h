#pragma once

#include "GameObject.h"

#include <glm/glm.hpp>

const float FAR = 100.0f;
const float NEAR = 0.1f;
const float FOV = 45.0f;

class Camera : public GameObject
{
public:
	float fov = FOV;
	float near = NEAR;
	float far = FAR;

public:
	Camera(Transform transform);
	Camera(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
	Camera(const Camera& rhs) = delete;
	virtual ~Camera();

public:
	virtual void Update(float deltaTime) override;
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjMatrix();

};

