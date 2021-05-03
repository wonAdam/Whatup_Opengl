#pragma once

#include "Light.h"
#include "GameObject.h"

class SpotLight : public Light, public GameObject
{
private:
	const float _cutOff = glm::cos(glm::radians(12.5f));
	const float _outerCutOff = glm::cos(glm::radians(15.0f));
	const float _constant = 1.0f;
	const float _linear = 0.09f;
	const float _quadratic = 0.032f;

public:
	SpotLight(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	SpotLight(const SpotLight& rhs) = delete;
	virtual ~SpotLight();

public:
	virtual void Update(float deltaTime) override;
	virtual void LoadUniformValue(unsigned int index, Shader& shader) override;
};

