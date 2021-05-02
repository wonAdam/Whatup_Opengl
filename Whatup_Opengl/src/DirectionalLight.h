#pragma once

#include "Light.h"
#include "GameObject.h"

class DirectionalLight : public Light, public GameObject
{
public:
	DirectionalLight(glm::vec3 rotation, glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular);
	DirectionalLight(const DirectionalLight& rhs) = delete;
	virtual ~DirectionalLight();
	virtual void Update(float deltaTime) override;
	
private:
	virtual void SetLightUniformValues(unsigned int index, Shader& shader) override;

	friend void Light::SetLightUniformValues(Shader& shader);
};

