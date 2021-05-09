#include "DirectionalLight.h"

#include "shaders/LightShader.h"
#include "Game.h"
#include "Camera.h"

DirectionalLight::DirectionalLight(std::string name, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: Cube(name, glm::vec3(0.0f), rotation, glm::vec3(1.0f, 1.0f, 0.2f)), Light(ambient, diffuse, specular, Type::DIRECTIONAL)
{
    _shader = std::unique_ptr<LightShader>(new LightShader(&_transform, _type));
}

DirectionalLight::~DirectionalLight()
{
}

void DirectionalLight::Update(float deltaTime)
{
    _mesh->Draw(*_shader, _transform);
}

void DirectionalLight::LoadUniformValue(const unsigned int index, const Shader& shader) const
{
    shader.setVec3("dirLight[" + std::to_string(index) + "].diffuse", _diffuse);
    shader.setVec3("dirLight[" + std::to_string(index) + "].ambient", _ambient);
    shader.setVec3("dirLight[" + std::to_string(index) + "].specular", _specular);
    shader.setVec3("dirLight[" + std::to_string(index) + "].direction", _transform.GetForward());
}
