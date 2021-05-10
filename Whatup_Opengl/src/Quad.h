#pragma once
#include "GameObject.h"

#include <vector>
#include <memory>

#include "Texture.h"
#include "Mesh.h"

class Quad : public GameObject
{
public:
    Quad(std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    Quad(std::vector<Texture> textures, std::string name, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
    Quad(const Quad& rhs) = delete;
    virtual ~Quad();

public:
    virtual void Update(float deltaTime) override;

private:
    std::unique_ptr<Mesh> _mesh;
    std::unique_ptr<Shader> _shader;
    std::vector<Vertex> _vertices = {
        // positions         // normals             // tex coord
        Vertex(0.5f, -0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f, 0.0f),  // bottom right
        Vertex(-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f),  // bottom left
        Vertex(-0.5f,  0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f, 1.0f),   // top left
        Vertex(0.5f,  0.5f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f, 1.0f)   // top right
    };
    std::vector<unsigned int> _indices = { 0,1,2,0,2,3 };
    std::vector<Texture> _textures = {
        Texture("img/container2.png", Texture::Type::DIFFUSE),
        Texture("img/doge.png", Texture::Type::DIFFUSE),
        Texture("img/container2_specular.png", Texture::Type::SPECULAR),
    };


};

