#include "Triangle.h"

#include <glm/gtc/matrix_transform.hpp>

#include "GLMacro.h"
#include "shaders/DefaultShader.h"

Triangle::Triangle(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(name, position, rotation, scale)
{
	_shader = std::unique_ptr<DefaultShader>(new DefaultShader(_transform));
	_mesh = std::unique_ptr<Mesh>(new Mesh(_vertices, _indices, _textures));
}

Triangle::~Triangle()
{
}

void Triangle::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
