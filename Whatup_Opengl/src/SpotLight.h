#pragma once

#include "Light.h"
#include "GameObject.h"

class SpotLight : public Light, public GameObject
{
public:
	float _cutOff = glm::cos(glm::radians(12.5f));
	float _outerCutOff = glm::cos(glm::radians(15.0f));

public:
	SpotLight(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	SpotLight(const SpotLight& rhs) = delete;
	virtual ~SpotLight();

public:
	virtual void Update(float deltaTime) override;
	virtual void LoadUniformValue(unsigned int index, Shader& shader) override;
};
