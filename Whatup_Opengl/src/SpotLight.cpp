#include "SpotLight.h"

#include "Shader.h"
#include "Game.h"
#include "Camera.h"
#include "GLMacro.h"

SpotLight::SpotLight(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: Cube(name, position, rotation, glm::vec3(0.2f, 0.2f, 0.8f)), Light(ambient, diffuse, specular, Type::SPOT)
{
    _shader = std::shared_ptr<Shader>(new Shader(WO_DEFAULT_VERTEX_SHADER, "shaders/LightFragment.frag"));
}

SpotLight::~SpotLight()
{
}

void SpotLight::Update(float deltaTime)
{
    _shader->use();

    _shader->setVec3("L_direction", _transform.GetForward());

    _shader->BindTexture(_textures);

    _shader->setInt("L_type", static_cast<int>(_type));

    // Set MVP
    _shader->setMat4("model", _transform.GetModelMatrix());
    _shader->setMat4("view", Game::GameCamera->GetViewMatrix());
    _shader->setMat4("proj", Game::GameCamera->GetProjMatrix());

    // draw mesh
    glBindVertexArray(_mesh->_VAO);
    glDrawElements(GL_TRIANGLES, _mesh->_indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
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

