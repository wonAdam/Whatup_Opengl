#include "Triangle.h"

#include <glm/gtc/matrix_transform.hpp>

#include "GLMacro.h"

Triangle::Triangle(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(name, position, rotation, scale)
{
	_shader = std::shared_ptr<Shader>(new Shader(WO_DEFAULT_VERTEX_SHADER, WO_DEFAULT_FRAGMENT_SHADER));
	_mesh = std::shared_ptr<Mesh>(new Mesh(vertices, indices, textures));
}

Triangle::Triangle(std::shared_ptr<Shader> shader, std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(name, position, rotation, scale)
{
	_shader = shader;
	_mesh = std::shared_ptr<Mesh>(new Mesh(vertices, indices, textures));
}

Triangle::~Triangle()
{
}

void Triangle::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
