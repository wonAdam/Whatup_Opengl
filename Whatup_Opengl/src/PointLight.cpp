#include "PointLight.h"

#include "Shader.h"

PointLight::PointLight(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: GameObject(name, position, glm::vec3(0.0f), glm::vec3(1.0f)), Light(ambient, diffuse, specular)
{
}

PointLight::~PointLight()
{
}

void PointLight::Update(float deltaTime)
{
}

void PointLight::LoadUniformValue(unsigned int index, Shader& shader)
{
    shader.setVec3("pointLights[" + std::to_string(index) + "].diffuse", _diffuse);
    shader.setVec3("pointLights[" + std::to_string(index) + "].ambient", _ambient);
    shader.setVec3("pointLights[" + std::to_string(index) + "].specular", _specular);
    shader.setVec3("pointLights[" + std::to_string(index) + "].position", _transform._position);
    shader.setFloat("pointLights[" + std::to_string(index) + "].constant", _constant);
    shader.setFloat("pointLights[" + std::to_string(index) + "].linear", _linear);
    shader.setFloat("pointLights[" + std::to_string(index) + "].quadratic", _quadratic);
}
