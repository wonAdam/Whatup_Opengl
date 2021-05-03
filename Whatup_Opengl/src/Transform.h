#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>

struct Transform
{
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

	Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
		: _position(position), _rotation(rotation), _scale(scale) 
	{}

	glm::mat4 GetModelMatrix() const
	{
		glm::mat4 scale = glm::scale(glm::mat4(1.0f), _scale);
		glm::mat4 trans = glm::translate(glm::mat4(1.0f), _position);
		float radX = glm::radians(_rotation.x), radY = glm::radians(_rotation.y), radZ = glm::radians(_rotation.z);
		glm::mat4 rot = glm::eulerAngleYXZ(radY, radX, radZ);
		return trans * rot * scale;
	}

	glm::vec3 GetForward() const
	{
		return GetModelMatrix() * glm::vec4(0.0f, 0.0f, -1.0f, 0.0f);
	}

	glm::vec3 GetUp() const
	{
		return GetModelMatrix() * glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	}

	glm::vec3 GetRight() const
	{
		return GetModelMatrix() * glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	}
};