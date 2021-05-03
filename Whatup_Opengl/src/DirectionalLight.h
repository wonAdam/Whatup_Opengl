#pragma once

#include "Light.h"
#include "GameObject.h"

class DirectionalLight : public Light, public GameObject
{
public:
	DirectionalLight(std::string name, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	DirectionalLight(const DirectionalLight& rhs) = delete;
	virtual ~DirectionalLight();

public:
	virtual void Update(float deltaTime) override;
	virtual void LoadUniformValue(unsigned int index, Shader& shader) override;
};

