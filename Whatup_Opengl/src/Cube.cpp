#include "Cube.h"

#include "Game.h"
#include "Camera.h"

Cube::Cube(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, std::shared_ptr<Shader> shader)
	: _shader(shader), GameObject(position, rotation, scale)
{
	_mesh = std::shared_ptr<Mesh>(new Mesh(_vertices, _textures));
}

Cube::~Cube()
{
}

void Cube::Update(float deltaTime)
{
	glm::mat4 model = glm::mat4(1.0f);
	_shader->SetMat4("model", model);
	_shader->SetMat4("view", Game::GameCamera->GetViewMatrix());
	_shader->SetMat4("proj", Game::GameCamera->GetProjMatrix());

	_mesh->Draw(*_shader);
}
