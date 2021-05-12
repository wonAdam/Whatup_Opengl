#include "Quad.h"

#include "GLMacro.h"
#include "shaders/DefaultShader.h"

Quad::Quad(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(name, position, rotation, scale)
{
	_shader = std::unique_ptr<DefaultShader>(new DefaultShader(&_transform));
	_mesh = std::unique_ptr<Mesh>(new Mesh(_vertices, _indices, _textures));
}

Quad::Quad(std::vector<Texture> textures, std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: GameObject(name, position, rotation, scale)
{
	_textures = textures;
	_shader = std::unique_ptr<DefaultShader>(new DefaultShader(&_transform));
	_mesh = std::unique_ptr<Mesh>(new Mesh(_vertices, _indices, _textures));
}

Quad::~Quad()
{
}

void Quad::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
