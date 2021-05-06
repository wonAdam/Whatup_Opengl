#include "Cube.h"

#include "GLMacro.h"

Cube::Cube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(name, position, rotation, scale)
{
	_shader = std::shared_ptr<Shader>(new Shader(WO_DEFAULT_VERTEX_SHADER, WO_DEFAULT_FRAGMENT_SHADER));
	_mesh = std::shared_ptr<Mesh>(new Mesh(_vertices, _textures));
}

Cube::~Cube()
{
}

void Cube::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
