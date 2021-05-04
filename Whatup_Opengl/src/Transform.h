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
		float radX = glm::radians(_rotation.x);
		float radY = glm::radians(_rotation.y);
		float radZ = glm::radians(_rotation.z);
		glm::mat4 rotX = glm::eulerAngleX(radX);
		glm::mat4 rotY = glm::eulerAngleY(radY);
		glm::mat4 rotZ = glm::eulerAngleZ(radZ);
		glm::mat4 rot = rotZ * rotY * rotX;
		return trans * rot * scale;
	}

	glm::vec3 GetForward() const
	{
		return glm::normalize(glm::vec3(-GetModelMatrix()[2]));
	}

	glm::vec3 GetUp() const
	{
		return glm::normalize(glm::vec3(GetModelMatrix()[1]));
	}

	glm::vec3 GetRight() const
	{
		return glm::normalize(glm::vec3(GetModelMatrix()[0]));
	}
};