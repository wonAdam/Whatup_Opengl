#include "DirectionalLight.h"

#include "Shader.h"

DirectionalLight::DirectionalLight(std::string name, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: GameObject(name, glm::vec3(0.0f), rotation, glm::vec3(1.0f)), Light(ambient, diffuse, specular)
{
}

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::Update(float deltaTime)
{
}

void DirectionalLight::LoadUniformValue(unsigned int index, Shader& shader)
{
    shader.setVec3("dirLight[" + std::to_string(index) + "].diffuse", _diffuse);
    shader.setVec3("dirLight[" + std::to_string(index) + "].ambient", _ambient);
    shader.setVec3("dirLight[" + std::to_string(index) + "].specular", _specular);
    shader.setVec3("dirLight[" + std::to_string(index) + "].direction", _transform.GetForward());
}
