#include "Cube.h"

#include "GLMacro.h"
#include "shaders/DefaultShader.h"

Cube::Cube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
    : GameObject(name, position, rotation, scale)
{
	_shader = std::unique_ptr<DefaultShader>(new DefaultShader(&_transform));
	_mesh = std::unique_ptr<Mesh>(new Mesh(_vertices, _textures));
}

Cube::~Cube()
{
}

void Cube::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
