#include "PointLight.h"

#include "shaders/LightShader.h"
#include "Game.h"
#include "Camera.h"

PointLight::PointLight(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: Cube(name, position, glm::vec3(0.0f), glm::vec3(0.3f)), Light(ambient, diffuse, specular, Type::POINT)
{
    // override
    _shader = std::unique_ptr<LightShader>(new LightShader(&_transform, _type));
}

PointLight::~PointLight()
{
}


void PointLight::LoadUniformValue(const unsigned int index, const Shader& shader) const
{
    shader.setVec3("pointLights[" + std::to_string(index) + "].diffuse", _diffuse);
    shader.setVec3("pointLights[" + std::to_string(index) + "].ambient", _ambient);
    shader.setVec3("pointLights[" + std::to_string(index) + "].specular", _specular);
    shader.setVec3("pointLights[" + std::to_string(index) + "].position", _transform._position);
    shader.setFloat("pointLights[" + std::to_string(index) + "].constant", _constant);
    shader.setFloat("pointLights[" + std::to_string(index) + "].linear", _linear);
    shader.setFloat("pointLights[" + std::to_string(index) + "].quadratic", _quadratic);
}
