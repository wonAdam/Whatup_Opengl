#pragma once

#include "gameobjects/GameObject.h"

#include <glm/glm.hpp>

// DEFAULT VALUES
const float FAR = 100.0f;
const float NEAR = 0.1f;
const float FOV = 45.0f;
const float SPEED = 20.0f;
const float SENSITIVITY = 0.1f;

class Camera : public GameObject
{
public:
	float fov = FOV;
	float near = NEAR;
	float far = FAR;
	float movementSpeed = SPEED;
	float sensitiviy = SENSITIVITY;
	bool FPSMode = true;

public:
	Camera(Transform transform);
	Camera(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
	Camera(const Camera& rhs) = delete;
	virtual ~Camera();

public:
	virtual void Update(float deltaTime) override;
	virtual void LateUpdate(float deltaTime) override;
	virtual void Render(float deltaTime) override;

public:
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjMatrix();

	void Rotate(float xoffset, float yoffset);
	void Move(float xoffset, float yoffset, float zoffset);
};

