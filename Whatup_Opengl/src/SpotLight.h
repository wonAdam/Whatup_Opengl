#pragma once

#include "Light.h"
#include "GameObject.h"

class SpotLight : public Light, public GameObject
{
public:
	const float cutOff = glm::cos(glm::radians(12.5f));
	const float outerCutOff = glm::cos(glm::radians(16.0f));

public:
	SpotLight(glm::vec3 position, glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular);
	SpotLight(const SpotLight& rhs) = delete;
	virtual ~SpotLight();
	virtual void Update(float deltaTime) override;
	
private:
	virtual void SetLightUniformValues(unsigned int index, Shader& shader) override;

	friend void Light::SetLightUniformValues(Shader& shader);
};

