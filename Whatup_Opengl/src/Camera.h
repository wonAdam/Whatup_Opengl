#pragma once

#include <glm/glm.hpp>

#include "GameObject.h"

const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 10.0f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera : public GameObject
{
	enum Camera_Movement {
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};

public:
	float MovementSpeed = SPEED;
	float MouseSensitivity = SENSITIVITY;
	float Zoom = ZOOM;

public:
	Camera(glm::vec3 position, glm::vec3 rotation = glm::vec3(PITCH, YAW, 0.0f));
	Camera(const Camera& rhs) = delete;
	virtual ~Camera();
	virtual void Update(float deltaTime) override;

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjMatrix();
	void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
};


