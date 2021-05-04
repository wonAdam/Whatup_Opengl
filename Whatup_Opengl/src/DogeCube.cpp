#include "DogeCube.h"

DogeCube::DogeCube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: Cube(name, position, rotation, scale)
{
	_shader = std::shared_ptr<Shader>(new Shader("shaders/VertexShader.vert", "shaders/FragmentShader.frag"));
	_mesh = std::shared_ptr<Mesh>(new Mesh(_vertices, _textures));
}

DogeCube::~DogeCube()
{
}

void DogeCube::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
