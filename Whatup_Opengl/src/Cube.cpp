#include "Cube.h"

Cube::Cube(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, Shader* shader)
	: _shader(shader), GameObject(position, rotation, scale)
{
	_mesh = std::shared_ptr<Mesh>(new Mesh(_vertices, _textures));
}

Cube::~Cube()
{
}

void Cube::Update(float deltaTime)
{
	_mesh->Draw(*_shader);
}
