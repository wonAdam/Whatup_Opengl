#include "DogeCube.h"

DogeCube::DogeCube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: Cube(name, position, rotation, scale)
{
    // overriding
    _textures = {
        Texture("img/doge.png", Texture::Type::DIFFUSE),
        Texture("img/container2.png", Texture::Type::DIFFUSE),
        Texture("img/container2_specular.png", Texture::Type::SPECULAR),
    };
    _mesh = std::unique_ptr<Mesh>(new Mesh(_vertices, _textures));
}

DogeCube::~DogeCube()
{
}

void DogeCube::Update(float deltaTime)
{
	_mesh->Draw(*_shader, _transform);
}
