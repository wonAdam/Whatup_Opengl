#include "SpotLight.h"

#include "Shader.h"

SpotLight::SpotLight(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: GameObject(name, position, rotation, glm::vec3(1.0f)), Light(ambient, diffuse, specular)
{
}

SpotLight::~SpotLight()
{
}

void SpotLight::Update(float deltaTime)
{
}

void SpotLight::LoadUniformValue(unsigned int index, Shader& shader)
{
    shader.setVec3("spotLights[" + std::to_string(index) + "].diffuse", _diffuse);
    shader.setVec3("spotLights[" + std::to_string(index) + "].ambient", _ambient);
    shader.setVec3("spotLights[" + std::to_string(index) + "].specular", _specular);
    shader.setVec3("spotLights[" + std::to_string(index) + "].position", _transform._position);
    shader.setVec3("spotLights[" + std::to_string(index) + "].direction", _transform.GetForward());
    shader.setFloat("spotLights[" + std::to_string(index) + "].cutOff", _cutOff);
    shader.setFloat("spotLights[" + std::to_string(index) + "].outerCutOff", _outerCutOff);

}

