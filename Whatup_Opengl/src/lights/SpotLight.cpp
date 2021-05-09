#include "SpotLight.h"

#include "shaders/LightShader.h"
#include "Game.h"
#include "Camera.h"
#include "GLMacro.h"

SpotLight::SpotLight(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: Cube(name, position, rotation, glm::vec3(0.2f, 0.2f, 0.8f)), Light(ambient, diffuse, specular, Type::SPOT)
{
    // override
    _shader = std::unique_ptr<LightShader>(new LightShader(&_transform, _type));
}

SpotLight::~SpotLight()
{
}

void SpotLight::Update(float deltaTime)
{
    _mesh->Draw(*_shader, _transform);
}


void SpotLight::LoadUniformValue(const unsigned int index, const Shader& shader) const
{
    shader.setVec3("spotLights[" + std::to_string(index) + "].diffuse", _diffuse);
    shader.setVec3("spotLights[" + std::to_string(index) + "].ambient", _ambient);
    shader.setVec3("spotLights[" + std::to_string(index) + "].specular", _specular);
    shader.setVec3("spotLights[" + std::to_string(index) + "].position", _transform._position);
    shader.setVec3("spotLights[" + std::to_string(index) + "].direction", _transform.GetForward());
    shader.setFloat("spotLights[" + std::to_string(index) + "].cutOff", _cutOff);
    shader.setFloat("spotLights[" + std::to_string(index) + "].outerCutOff", _outerCutOff);

}

