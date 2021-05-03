#pragma once

#include "Light.h"
#include "GameObject.h"

class PointLight : public Light, public GameObject
{
public:
	float _constant = 1.0f;
	float _linear = 0.09f;
	float _quadratic = 0.032f;


public:
	PointLight(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	PointLight(const PointLight& rhs) = delete;
	virtual ~PointLight();

public:
	virtual void Update(float deltaTime) override;
	virtual void LoadUniformValue(unsigned int index, Shader& shader) override;

};

