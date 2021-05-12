#include "Grass.h"
#include "Texture.h"
#include "shaders/DefaultShader.h"
#include <memory.h>

Grass::Grass(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: Quad(name, position, rotation, scale)
{
	// override
	_textures = { Texture("img/grass.png", Texture::Type::DIFFUSE) };
	_shader = std::unique_ptr<DefaultShader>(new DefaultShader(&_transform));
	_mesh = std::unique_ptr<Mesh>(new Mesh(_vertices, _indices, _textures));
}

Grass::~Grass()
{
}

void Grass::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
