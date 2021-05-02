#pragma once
#include <vector>
#include <glm/glm.hpp>

class Shader;

class Light
{
public:
	enum TYPE{ DIRECTIONAL = 0, SPOT = 1, POINT = 2 };
	static std::vector<Light*> lights;
	static unsigned char lightCnt[3];

public:
	glm::vec3 _diffuse;
	glm::vec3 _ambient;
	glm::vec3 _specular;

public:
	static void SetLightUniformValues(Shader& shader);

protected:
	Light(glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular);
	virtual ~Light();
	virtual void Update(float deltaTime) = 0;
	virtual void SetLightUniformValues(unsigned int index, Shader& shader) = 0;
};

