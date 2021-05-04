#include "Cube.h"

Cube::Cube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(name, position, rotation, scale)
{
	_shader = std::shared_ptr<Shader>(new Shader("shaders/VertexShader.vert", "shaders/FragmentShader.frag"));
	_mesh = std::shared_ptr<Mesh>(new Mesh(vertices, textures));
}

Cube::~Cube()
{
}

void Cube::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
