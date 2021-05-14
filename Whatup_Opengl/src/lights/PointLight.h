#pragma once

#include "Light.h"
#include "gameobjects/GameObject.h"
#include "gameobjects/Cube.h"

class PointLight : public Light, public Cube
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
	using Cube::Update;
	using Cube::LateUpdate;
	using Cube::Render;
	virtual void LoadUniformValue(const unsigned int index, const Shader& shader) const override;

};

