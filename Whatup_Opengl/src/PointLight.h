#pragma once

#include "Light.h"
#include "GameObject.h"

class PointLight : public Light, public GameObject
{
public:
	const float constant = 1.0f;
	const float linear = 0.023f;
	const float quadratic = 0.033f;

public:
	PointLight(glm::vec3 position, glm::vec3 rotation, glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular);
	PointLight(const PointLight& rhs) = delete;
	virtual ~PointLight();
	virtual void Update(float deltaTime) override;
	
private:
	virtual void SetLightUniformValues(unsigned int index, Shader& shader) override;

	friend void Light::SetLightUniformValues(Shader& shader);
};

