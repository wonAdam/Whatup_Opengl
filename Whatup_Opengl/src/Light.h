#pragma once

#include <glm/glm.hpp>

class Shader;

class Light
{
public:
	enum TYPE { DIRECTIONAL = 0, POINT = 1, SPOT = 2 };
	#define LIGHT_TPYE_COUNT 3
public:
	glm::vec3 _ambient;
	glm::vec3 _diffuse;
	glm::vec3 _specular;

protected:
	Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	Light(const Light& rhs) = delete;
	virtual ~Light();

public:
	virtual void LoadUniformValue(unsigned int index, Shader& shader) = 0;
};
