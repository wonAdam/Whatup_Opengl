#include "PointLight.h"

PointLight::PointLight(glm::vec3 position, glm::vec3 rotation, glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular)
	: Light(diffuse, ambient, specular), GameObject(position, rotation, glm::vec3(1.0f))
{
}

PointLight::~PointLight()
{
}

void PointLight::Update(float deltaTime)
{
}

void PointLight::SetLightUniformValues(unsigned int index, Shader& shader)
{
}
