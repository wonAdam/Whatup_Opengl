#include "DirectionalLight.h"

#include "Shader.h"

DirectionalLight::DirectionalLight(glm::vec3 rotation, glm::vec3 diffuse, glm::vec3 ambient, glm::vec3 specular)
	: Light(diffuse, ambient, specular), GameObject(glm::vec3(0.0f), rotation, glm::vec3(1.0f))
{
}

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::Update(float deltaTime)
{
}

void DirectionalLight::SetLightUniformValues(unsigned int index, Shader& shader)
{
	shader.SetVec3("dirLight[" + std::to_string(index) + "].direction", GetForward());
	shader.SetVec3("dirLight[" + std::to_string(index) + "].diffuse", _diffuse);
	shader.SetVec3("dirLight[" + std::to_string(index) + "].ambient", _ambient);
	shader.SetVec3("dirLight[" + std::to_string(index) + "].specular", _specular);
}
