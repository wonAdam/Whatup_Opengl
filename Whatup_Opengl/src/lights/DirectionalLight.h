#pragma once

#include "Light.h"
#include "gameobjects/GameObject.h"
#include "gameobjects/Cube.h"

class DirectionalLight : public Light, public Cube
{
public:
	DirectionalLight(std::string name, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
	DirectionalLight(const DirectionalLight& rhs) = delete;
	virtual ~DirectionalLight();

public:
	using Cube::Update;
	using Cube::LateUpdate;
	using Cube::Render;
	virtual void LoadUniformValue(const unsigned int index, const Shader& shader) const override;
};

