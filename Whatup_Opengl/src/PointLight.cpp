#include "PointLight.h"

#include "Shader.h"
#include "Game.h"
#include "Camera.h"

PointLight::PointLight(std::string name, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
	: Cube(name, position, glm::vec3(0.0f), glm::vec3(0.3f)), Light(ambient, diffuse, specular, Type::POINT)
{
    _shader = std::shared_ptr<Shader>(new Shader("shaders/VertexShader.vert", "shaders/LightFragment.frag"));
}

PointLight::~PointLight()
{
}

void PointLight::Update(float deltaTime)
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
