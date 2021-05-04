#pragma once
#include "Cube.h"
class DogeCube : public Cube
{
public:
    DogeCube(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    DogeCube(const DogeCube& rhs) = delete;
    virtual ~DogeCube();

public:
    virtual void Update(float deltaTime) override;

private:
    std::vector<Texture> _textures = {
        Texture("img/doge.png", Texture::Type::DIFFUSE),
        Texture("img/container2.png", Texture::Type::DIFFUSE),
        Texture("img/container2_specular.png", Texture::Type::SPECULAR),
    };
};

